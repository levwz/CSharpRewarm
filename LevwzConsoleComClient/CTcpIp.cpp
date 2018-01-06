#include "stdafx.h"
#include "CTcpIp.h"
#include <winsock.h>
#include <iostream>
#include <atlbase.h>
#include <atlcom.h>
#include <fileapi.h>
#include <atlfile.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define PACKAGE_SIZE 4096
#define BUFFER_SIZE 1024

CTcpIp::CTcpIp()
{
	
}


CTcpIp::~CTcpIp()
{
}

void CTcpIp::Test()
{
	int iResult = StartTcpIpService();

	if (0 != iResult)
	{
		cout << "error occured while start service";
		return;
	}
	iResult = Connect(5099, "127.0.0.1");

	if (0 != iResult)
	{
		cout << "error occured while connect";
		return;
	}
	char receiveBuff[1024] = { 0 };
	int x = 0;
	do 
	{		
		char receive[10] = { 0 };
		iResult = Receive(receive, sizeof(receive));
		memcpy(receiveBuff+x, receive, iResult);

		x += iResult;

	}while (iResult==sizeof(char)*10);
	
	std::cout << receiveBuff << std::endl;

	Upload("fileName");

	char send[] = "\0Hello, this is the message from client";

	iResult = Send(send, sizeof(send));

	char *pSend = new char[40960];

	memset(pSend, 'A', sizeof(char) * 40960);

	iResult = Send(pSend, sizeof(char) * 40960);
	cout << "sent: " << pSend << endl;
	delete[] pSend;

	pSend = NULL;

	StopTcpIpService();
}

int CTcpIp::Receive(char* pBuff, int length)
{
	return recv(m_socket, pBuff, length, 0);
}

int CTcpIp::Send(char* pBuff, int length)
{
	return send(m_socket, pBuff, length, 0); 
}

int CTcpIp::Upload(std::string fileName)
{
	HANDLE hFile = ::CreateFile(_T("TestFile.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

	DWORD dwError = GetLastError();
	
	DWORD dwRead = 0;
	DWORD dwTotal = 0;
	OVERLAPPED overlapped = { 0 };
	BOOL bSuccess = FALSE;
	do 
	{
		char *pBuff = new char[PACKAGE_SIZE];
		memset(pBuff, 0, sizeof(char) * PACKAGE_SIZE);

		bSuccess = ReadFile(hFile, pBuff, sizeof(char) * PACKAGE_SIZE, &dwRead, NULL);


		
		Sleep(1000);
		if (0 == dwRead) {
			break;
		}

		int i = Send(pBuff, dwRead*sizeof(char));
		if (SOCKET_ERROR == i) {
			cout << WSAGetLastError() << ";" << "returned " << i << "failed sent " << dwRead << endl;
		}
		else {
			cout << "sent " << i << endl;
		}
		

		delete[] pBuff;

/*		char buff[BUFFER_SIZE] = { 0 };

		i = Receive(buff, BUFFER_SIZE * sizeof(char));

		if (SOCKET_ERROR == i)
		{
			cout << WSAGetLastError()<<endl;
		}*/
	} while (bSuccess);

	return -1;
}

int CTcpIp::Download(std::string, LONG size)
{
	return -1;
}

int CTcpIp::StartTcpIpService() 
{
	if (m_ptrTcpIp)
	{
		return 0;
	}

	CoInitialize(NULL);

	CComPtr<IAtlObject> p = NULL;
	CLSID clsid = __uuidof(AtlObject);
	HRESULT hr = p.CoCreateInstance(clsid);

	if (FAILED(hr))
	{
		return -1;
	}
	
	hr = p->QueryInterface(&m_ptrTcpIp);
	
	if (FAILED(hr))
	{
		return -1;
	}

	LONG lPort = 0;
	hr = m_ptrTcpIp->StartTcpIpService(5099, &lPort);

	if (FAILED(hr))
	{
		return -1;
	}
	return 0;

}

int CTcpIp::StopTcpIpService()
{
	if (m_ptrTcpIp == NULL)
	{
		return 0;
	}
	
	m_ptrTcpIp->StopTcpIpService();

	m_ptrTcpIp.Release();

	CoUninitialize();

}
int CTcpIp::Connect(LONG lPort, std::string ip)
{
	WSADATA wsaData;

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0)
	{
		std::cout << "Failed to load Winsock" << std::endl;

		return iResult;
	}

	SOCKADDR_IN addrSrv;// = { AF_INET, 5099,NULL , NULL };
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(5099);
	addrSrv.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == m_socket)
	{
		std::cout << "socket() error " << WSAGetLastError() << std::endl;
		return SOCKET_ERROR;
	}
	iResult = connect(m_socket, (sockaddr*)&addrSrv, sizeof(addrSrv));

	if (iResult == INVALID_SOCKET)
	{
		std::cout << "Connect failed " << WSAGetLastError() << std::endl;
		return iResult;
	}

	return iResult;
}

void CTcpIp::Disconnect()
{
	if (m_socket == NULL) 
	{
		return;
	}
	closesocket(m_socket);

	WSACleanup();
}
void CTcpIp::Run()
{
	WSADATA wsaData;

	char buff[1024];

	memset(buff, 0, sizeof(buff));

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		std::cout << "Failed to load Winsock" << std::endl;

		return;
	}

	SOCKADDR_IN addrSrv;// = { AF_INET, 5099,NULL , NULL };
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(5099);
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == sockClient)
	{
		std::cout << "socket() error " << WSAGetLastError() << std::endl;
		return;
	}

	if (connect(sockClient, (sockaddr*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET)
	{
		std::cout << "Connect failed " << WSAGetLastError() << std::endl;
		return;
	}

	recv(sockClient, buff, sizeof(buff), 0);
	std::cout << buff << std::endl;

	char databuff[] = "Hello, this is a client....";
	send(sockClient, databuff, sizeof(databuff), 0);

	closesocket(sockClient);

	WSACleanup();


}