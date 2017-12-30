

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for LevwzComAtlSvr.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __LevwzComAtlSvr_i_h__
#define __LevwzComAtlSvr_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ILevwzComAtlSvr_FWD_DEFINED__
#define __ILevwzComAtlSvr_FWD_DEFINED__
typedef interface ILevwzComAtlSvr ILevwzComAtlSvr;

#endif 	/* __ILevwzComAtlSvr_FWD_DEFINED__ */


#ifndef __IAtlObjectEx_FWD_DEFINED__
#define __IAtlObjectEx_FWD_DEFINED__
typedef interface IAtlObjectEx IAtlObjectEx;

#endif 	/* __IAtlObjectEx_FWD_DEFINED__ */


#ifndef __LevwzComAtlSvr_FWD_DEFINED__
#define __LevwzComAtlSvr_FWD_DEFINED__

#ifdef __cplusplus
typedef class LevwzComAtlSvr LevwzComAtlSvr;
#else
typedef struct LevwzComAtlSvr LevwzComAtlSvr;
#endif /* __cplusplus */

#endif 	/* __LevwzComAtlSvr_FWD_DEFINED__ */


#ifndef __AtlObject_FWD_DEFINED__
#define __AtlObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class AtlObject AtlObject;
#else
typedef struct AtlObject AtlObject;
#endif /* __cplusplus */

#endif 	/* __AtlObject_FWD_DEFINED__ */


#ifndef ___IAtlObjectExEvents_FWD_DEFINED__
#define ___IAtlObjectExEvents_FWD_DEFINED__
typedef interface _IAtlObjectExEvents _IAtlObjectExEvents;

#endif 	/* ___IAtlObjectExEvents_FWD_DEFINED__ */


#ifndef __AtlObjectEx_FWD_DEFINED__
#define __AtlObjectEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class AtlObjectEx AtlObjectEx;
#else
typedef struct AtlObjectEx AtlObjectEx;
#endif /* __cplusplus */

#endif 	/* __AtlObjectEx_FWD_DEFINED__ */


#ifndef __IAtlObject_FWD_DEFINED__
#define __IAtlObject_FWD_DEFINED__
typedef interface IAtlObject IAtlObject;

#endif 	/* __IAtlObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ILevwzComAtlSvr_INTERFACE_DEFINED__
#define __ILevwzComAtlSvr_INTERFACE_DEFINED__

/* interface ILevwzComAtlSvr */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ILevwzComAtlSvr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d463914f-e174-49ad-8405-acda2ea7befe")
    ILevwzComAtlSvr : public IDispatch
    {
    public:
        virtual /* [id][helpstring] */ HRESULT STDMETHODCALLTYPE ReadConfiguration( 
            /* [in] */ BSTR __MIDL__ILevwzComAtlSvr0000) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ILevwzComAtlSvrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILevwzComAtlSvr * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILevwzComAtlSvr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILevwzComAtlSvr * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILevwzComAtlSvr * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILevwzComAtlSvr * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILevwzComAtlSvr * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILevwzComAtlSvr * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadConfiguration )( 
            ILevwzComAtlSvr * This,
            /* [in] */ BSTR __MIDL__ILevwzComAtlSvr0000);
        
        END_INTERFACE
    } ILevwzComAtlSvrVtbl;

    interface ILevwzComAtlSvr
    {
        CONST_VTBL struct ILevwzComAtlSvrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILevwzComAtlSvr_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ILevwzComAtlSvr_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ILevwzComAtlSvr_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ILevwzComAtlSvr_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ILevwzComAtlSvr_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ILevwzComAtlSvr_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ILevwzComAtlSvr_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ILevwzComAtlSvr_ReadConfiguration(This,__MIDL__ILevwzComAtlSvr0000)	\
    ( (This)->lpVtbl -> ReadConfiguration(This,__MIDL__ILevwzComAtlSvr0000) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ILevwzComAtlSvr_INTERFACE_DEFINED__ */


#ifndef __IAtlObjectEx_INTERFACE_DEFINED__
#define __IAtlObjectEx_INTERFACE_DEFINED__

/* interface IAtlObjectEx */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAtlObjectEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("bb0fa7f2-1bd3-41e2-b4a2-7c518ecfb5eb")
    IAtlObjectEx : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DoInitSomething( 
            /* [out][in] */ LONG *param1,
            /* [out][in] */ LONG *param2,
            /* [retval][out] */ LONG *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAtlObjectExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAtlObjectEx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAtlObjectEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAtlObjectEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAtlObjectEx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAtlObjectEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAtlObjectEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAtlObjectEx * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DoInitSomething )( 
            IAtlObjectEx * This,
            /* [out][in] */ LONG *param1,
            /* [out][in] */ LONG *param2,
            /* [retval][out] */ LONG *result);
        
        END_INTERFACE
    } IAtlObjectExVtbl;

    interface IAtlObjectEx
    {
        CONST_VTBL struct IAtlObjectExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAtlObjectEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAtlObjectEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAtlObjectEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAtlObjectEx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAtlObjectEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAtlObjectEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAtlObjectEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAtlObjectEx_DoInitSomething(This,param1,param2,result)	\
    ( (This)->lpVtbl -> DoInitSomething(This,param1,param2,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAtlObjectEx_INTERFACE_DEFINED__ */



#ifndef __LevwzComAtlSvrLib_LIBRARY_DEFINED__
#define __LevwzComAtlSvrLib_LIBRARY_DEFINED__

/* library LevwzComAtlSvrLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_LevwzComAtlSvrLib;

EXTERN_C const CLSID CLSID_LevwzComAtlSvr;

#ifdef __cplusplus

class DECLSPEC_UUID("70E54929-74C2-470B-B095-F1C4D399A76B")
LevwzComAtlSvr;
#endif

EXTERN_C const CLSID CLSID_AtlObject;

#ifdef __cplusplus

class DECLSPEC_UUID("b207549b-337d-48b8-b427-556d5754059d")
AtlObject;
#endif

#ifndef ___IAtlObjectExEvents_DISPINTERFACE_DEFINED__
#define ___IAtlObjectExEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IAtlObjectExEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IAtlObjectExEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("b3f927e1-afde-4e6a-8347-9cd645e87897")
    _IAtlObjectExEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IAtlObjectExEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IAtlObjectExEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IAtlObjectExEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IAtlObjectExEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IAtlObjectExEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IAtlObjectExEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IAtlObjectExEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IAtlObjectExEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IAtlObjectExEventsVtbl;

    interface _IAtlObjectExEvents
    {
        CONST_VTBL struct _IAtlObjectExEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IAtlObjectExEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IAtlObjectExEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IAtlObjectExEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IAtlObjectExEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IAtlObjectExEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IAtlObjectExEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IAtlObjectExEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IAtlObjectExEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AtlObjectEx;

#ifdef __cplusplus

class DECLSPEC_UUID("a2dbbaca-e69a-4994-b984-f509f9ec3537")
AtlObjectEx;
#endif
#endif /* __LevwzComAtlSvrLib_LIBRARY_DEFINED__ */

#ifndef __IAtlObject_INTERFACE_DEFINED__
#define __IAtlObject_INTERFACE_DEFINED__

/* interface IAtlObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAtlObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58ae78a0-dcff-4a4f-be19-9153fee51da3")
    IAtlObject : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ LONG para1,
            LONG para2,
            /* [retval][out] */ LONG *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAtlObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAtlObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAtlObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAtlObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAtlObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAtlObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAtlObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAtlObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAtlObject * This,
            /* [in] */ LONG para1,
            LONG para2,
            /* [retval][out] */ LONG *result);
        
        END_INTERFACE
    } IAtlObjectVtbl;

    interface IAtlObject
    {
        CONST_VTBL struct IAtlObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAtlObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAtlObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAtlObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAtlObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAtlObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAtlObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAtlObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAtlObject_Add(This,para1,para2,result)	\
    ( (This)->lpVtbl -> Add(This,para1,para2,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAtlObject_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


