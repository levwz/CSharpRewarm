// AtlObjectEx.cpp: CAtlObjectEx 的实现

#include "stdafx.h"
#include "AtlObjectEx.h"

#include <iostream>
// CAtlObjectEx



STDMETHODIMP CAtlObjectEx::DoInitSomething(LONG* param1, LONG* param2, LONG* result)
{
	if (param1 == NULL) {
		return E_INVALIDARG;
	}
	*result = *param1 + *param2;
	return S_OK;
}


unsigned __stdcall Run1(void* lp) {
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
	WSACleanup(); 
	_endthreadex(0);
		//system("pause");
}

STDMETHODIMP CAtlObjectEx::StartTcpIpService(LONG lPort, LONG* plPort)
{
	
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, NULL, Run1, NULL, NULL, NULL);
	
	if (hThread == NULL) {
		return E_FAIL;
	}

	

	return S_OK;
}




STDMETHODIMP CAtlObjectEx::StopTcpIpService()
{
	// TODO: 在此添加实现代码

	return S_OK;
}
