// AtlObject.h: CAtlObject 的声明

#pragma once
#include "resource.h"       // 主符号
#include <iostream>


#include "LevwzComAtlSvr_i.h" 



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CAtlObject

class ATL_NO_VTABLE CAtlObject :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAtlObject, &CLSID_AtlObject>,
	public IDispatchImpl<IAtlObject, &IID_IAtlObject, &LIBID_LevwzComAtlSvrLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<IAtlObjectEx, &__uuidof(IAtlObjectEx)>,
	public IDispatchImpl<ILevwzComAtlSvr, &__uuidof(ILevwzComAtlSvr)>
{
public:
	CAtlObject():m_dwServiceState(0), m_hThread(NULL)
	{
		std::cout << "Atl Object created" << std::endl;
	}

	DECLARE_REGISTRY_RESOURCEID(106)


	BEGIN_COM_MAP(CAtlObject)
		COM_INTERFACE_ENTRY(IAtlObject)
		COM_INTERFACE_ENTRY2(IDispatch, IAtlObjectEx)
		COM_INTERFACE_ENTRY(IAtlObjectEx)
		COM_INTERFACE_ENTRY(ILevwzComAtlSvr)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(Add)(LONG para1, LONG para2, LONG* result);

	// IAtlObjectEx Methods
public:
	STDMETHOD(DoInitSomething)(LONG * param1, LONG * param2, LONG * result)
	{
		*result = *param1 * *param2;
		// 在此处添加函数实现。
		return E_NOTIMPL;
	}

	// ILevwzComAtlSvr Methods
public:
	STDMETHOD(ReadConfiguration)(BSTR)
	{
		// 在此处添加函数实现。
		return E_NOTIMPL;
	}
	
	STDMETHOD(StartTcpIpService)(LONG lport, LONG* plPort);
	STDMETHOD(StopTcpIpService)();
	volatile DWORD m_dwServiceState;
private:
	
	HANDLE m_hThread;
};

OBJECT_ENTRY_AUTO(__uuidof(AtlObject), CAtlObject)

