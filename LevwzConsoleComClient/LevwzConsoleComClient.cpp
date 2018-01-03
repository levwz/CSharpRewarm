// LevwzConsoleComClient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <objbase.h>
#include "../LevwzComAtlSvr/LevwzComAtlSvr_i.h"
#include "../LevwzComAtlSvr/LevwzComAtlSvr_i.c"
#include "CTcpIp.h"
#include <iostream>
#include <atlbase.h>
#include <atlcom.h>
using namespace std;
int main()
{
	/*WSADATA wsaData;
	int port = 5099;

	char buff[] = "Server: Hey, the message is from server...";

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "Failed to laod winsock" << std::endl;
		return 1;
	}

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(port);
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	int retVal = bind(sockSrv, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN));

	if (retVal == SOCKET_ERROR) {
		std::cout << "Failed bind %d\n" << WSAGetLastError();
		return 1;
	}

	if (listen(sockSrv, 10) == SOCKET_ERROR)
	{
		std::cout << "Listen failed %d" << WSAGetLastError();
		return 1;
	}

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	while (1)
	{
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
		if (sockConn == SOCKET_ERROR)
		{
			std::cout << "Accpet failed %d" << WSAGetLastError();
			break;
		}

		std::cout << "Accept client ip [" << inet_ntoa(addrClient.sin_addr) << "]" << std::endl;

		int iSend = send(sockConn, buff, sizeof(buff), 0);
		if (iSend == SOCKET_ERROR)
		{
			std::cout << "send failed" << std::endl;
			break;
		}

		char recvBuf[100];
		memset(recvBuf, 0, sizeof(recvBuf));

		recv(sockConn, recvBuf, sizeof(recvBuf), 0);

		std::cout << recvBuf << std::endl;

		closesocket(sockConn);

	}

	closesocket(sockSrv);
	WSACleanup();*/
	//_endthreadex(0);
	//system("pause");

	CoInitialize(NULL);

	CTcpIp tcpip;

	tcpip.Run();

	IAtlObject *p = NULL;
	CLSID clsid = __uuidof(AtlObject);
	//HRESULT hr = CLSIDFromString(OLESTR("{b207549b-337d-48b8-b427-556d5754059d}"), &clsid);

	CComPtr<IAtlObject> ptr;
	CComPtr<ILevwzComAtlSvr> ptrLevwz;
	HRESULT hr = ptr.CoCreateInstance(clsid);
	hr = ::CoCreateInstance(__uuidof(AtlObject), NULL, CLSCTX_LOCAL_SERVER, IID_ILevwzComAtlSvr, (LPVOID*)&ptrLevwz);

	if (SUCCEEDED(hr)) 
	{
		CComBSTR bstr = _T("123456778");
		hr = ptrLevwz->ReadConfiguration(bstr);
	}
	LONG x = 0;
	cout << endl << hr << endl << x << endl << ptr->Add(1,2,&x)<<endl << &clsid <<endl << x;
	hr = ptr->Add(5, 6, &x);
	UUID uuid;
	CComPtr<IAtlObjectEx> ptrEx;
	hr = ptr->QueryInterface(&ptrEx);

	LONG  y=2, z=0;
	hr = ptrEx->DoInitSomething(&x, &y, &z);

	CComPtr<ILevwzComAtlSvr> ptrAtlSvr;

	hr = ptr->QueryInterface(&ptrAtlSvr);

	hr = ptrEx->QueryInterface(&ptrAtlSvr);

	CComPtr<IUnknown> ptrUnkonwn;
	hr = ptrEx->QueryInterface(&ptrUnkonwn);
	//IID iid = IID_ILevwzComAtlSvr;
	

	//ptr->QueryInterface(iid, &ptrAtlSvr);
	ptr.Release();

	hr = CLSIDFromString(OLESTR("{a2dbbaca-e69a-4994-b984-f509f9ec3537}"), &clsid);

	CComPtr<IAtlObjectEx> ptrx;

	ptrx.CoCreateInstance(__uuidof(AtlObjectEx));
	hr = ptrx->DoInitSomething(&x, &y, &z);
	ptrx->QueryInterface(&ptr);
	clsid = __uuidof(AtlObject);
	CLSID cid = CComCoClass<AtlObject>::GetObjectCLSID();
	CoUninitialize();
    return 0;
}

