// AtlObjectEx.h: CAtlObjectEx 的声明

#pragma once
#include "resource.h"       // 主符号



#include "LevwzComAtlSvr_i.h"
#include "_IAtlObjectExEvents_CP.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CAtlObjectEx

class ATL_NO_VTABLE CAtlObjectEx :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAtlObjectEx, &CLSID_AtlObjectEx>,
	public IConnectionPointContainerImpl<CAtlObjectEx>,
	public CProxy_IAtlObjectExEvents<CAtlObjectEx>,
	public IDispatchImpl<IAtlObjectEx, &IID_IAtlObjectEx, &LIBID_LevwzComAtlSvrLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAtlObjectEx()
	{
	}

DECLARE_REGISTRY_RESOURCEID(107)


BEGIN_COM_MAP(CAtlObjectEx)
	COM_INTERFACE_ENTRY(IAtlObjectEx)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CAtlObjectEx)
	CONNECTION_POINT_ENTRY(__uuidof(_IAtlObjectExEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(DoInitSomething)(LONG* param1, LONG* param2, LONG* result);
	STDMETHOD(StartTcpIpService)(LONG lPort, LONG* plPort);
	STDMETHOD(StopTcpIpService)();

private:

	
};

OBJECT_ENTRY_AUTO(__uuidof(AtlObjectEx), CAtlObjectEx)
