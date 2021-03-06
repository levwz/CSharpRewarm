// AtlObject.cpp: CAtlObject 的实现

#include "stdafx.h"
#include "AtlObject.h"


// CAtlObject



STDMETHODIMP CAtlObject::Add(LONG para1, LONG para2, LONG* result)
{
	// TODO: 在此添加实现代码

	if (result == NULL) {
		result = new LONG;
	}

	*result = para1 + para2;

	return S_OK;
}

unsigned __stdcall Run(void* lp) {
	WSADATA wsaData;
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

	CAtlObject* p = (CAtlObject*)lp;
	while (p->m_dwServiceState)
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

		while(recv(sockConn, recvBuf, sizeof(recvBuf), 0));

		std::cout << recvBuf << std::endl;

		//closesocket(sockConn);

	}

	closesocket(sockSrv);
	WSACleanup();
	_endthreadex(0);
	//system("pause");

	return 0;
}

STDMETHODIMP CAtlObject::StartTcpIpService(LONG lPort, LONG* plPort)
{
	HANDLE m_hThread = (HANDLE)_beginthreadex(NULL, NULL, Run, this, NULL, NULL);

	if (m_hThread == NULL) {
		return E_FAIL;
	}

	m_dwServiceState = 1;// RUNNING
	
	return S_OK;
}



STDMETHODIMP CAtlObject::StopTcpIpService()
{
	m_dwServiceState = 0;

	return S_OK;
}
