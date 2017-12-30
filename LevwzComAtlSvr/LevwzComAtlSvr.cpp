// LevwzComAtlSvr.cpp: WinMain 的实现


#include "stdafx.h"
#include "resource.h"
#include "LevwzComAtlSvr_i.h"


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



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

