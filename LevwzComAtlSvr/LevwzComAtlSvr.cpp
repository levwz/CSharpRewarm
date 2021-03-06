// LevwzComAtlSvr.cpp: WinMain 的实现


#include "stdafx.h"
#include "resource.h"
#include "LevwzComAtlSvr_i.h"
#include <iostream>
#include <WinSock.h>

#pragma comment(lib, "ws2_32.lib")
using namespace ATL;

#include <stdio.h>

class CLevwzComAtlSvrModule : public ATL::CAtlServiceModuleT< CLevwzComAtlSvrModule, IDS_SERVICENAME >
{
public :
	DECLARE_LIBID(LIBID_LevwzComAtlSvrLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LEVWZCOMATLSVR, "{d463914f-e174-49ad-8405-acda2ea7befe}")
	HRESULT InitializeSecurity() throw()
	{
		// TODO : 调用 CoInitializeSecurity 并为服务提供适当的安全设置
		// 建议 - PKT 级别的身份验证、
		// RPC_C_IMP_LEVEL_IDENTIFY 的模拟级别
		// 以及适当的非 NULL 安全描述符。

		return S_OK;
	}
};

CLevwzComAtlSvrModule _AtlModule;

unsigned __stdcall  runTcpIpLoop(void *)
{
	WSADATA wsaData = { 0 };
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
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");// htonl(INADDR_ANY);

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
		if(iSend == SOCKET_ERROR)
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
	system("pause");

	return 0;
}

//
extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
								LPTSTR lpCmdLine, int nShowCmd)
{
	//HANDLE hThread = (HANDLE)_beginthreadex(NULL, NULL, runTcpIpLoop, NULL, NULL, NULL);
	//if(nShowCmd == 0xa)runTcpIpLoop();
	return _AtlModule.WinMain(nShowCmd);
}

