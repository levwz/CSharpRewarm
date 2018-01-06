#pragma once
#include <atlbase.h>
#include <atlcom.h>
#include <string>

#include "../LevwzComAtlSvr/LevwzComAtlSvr_i.h"
#include "../LevwzComAtlSvr/LevwzComAtlSvr_i.c"


class CTcpIp
{
public:
	CTcpIp();
	~CTcpIp();
	void Test();
private:

	int StartTcpIpService();
	int StopTcpIpService();
	void Run();
	int Receive(char* buff, int length);

	int Send(char* buff, int length);
	int Connect(LONG lPort, std::string);

	int Upload(std::string);
	int Download(std::string, LONG size);
	void Disconnect();
private:
	CComPtr<IAtlObjectEx> m_ptrTcpIp;
	SOCKET m_socket;
};

