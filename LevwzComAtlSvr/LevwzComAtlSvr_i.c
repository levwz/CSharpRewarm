

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ILevwzComAtlSvr,0xd463914f,0xe174,0x49ad,0x84,0x05,0xac,0xda,0x2e,0xa7,0xbe,0xfe);


MIDL_DEFINE_GUID(IID, IID_IAtlObjectEx,0xbb0fa7f2,0x1bd3,0x41e2,0xb4,0xa2,0x7c,0x51,0x8e,0xcf,0xb5,0xeb);


MIDL_DEFINE_GUID(IID, LIBID_LevwzComAtlSvrLib,0xC38792E5,0x33B6,0x4B3B,0x83,0xF8,0x38,0xAE,0x3C,0xC4,0x69,0xF1);


MIDL_DEFINE_GUID(CLSID, CLSID_LevwzComAtlSvr,0x70E54929,0x74C2,0x470B,0xB0,0x95,0xF1,0xC4,0xD3,0x99,0xA7,0x6B);


MIDL_DEFINE_GUID(CLSID, CLSID_AtlObject,0xb207549b,0x337d,0x48b8,0xb4,0x27,0x55,0x6d,0x57,0x54,0x05,0x9d);


MIDL_DEFINE_GUID(IID, DIID__IAtlObjectExEvents,0xb3f927e1,0xafde,0x4e6a,0x83,0x47,0x9c,0xd6,0x45,0xe8,0x78,0x97);


MIDL_DEFINE_GUID(CLSID, CLSID_AtlObjectEx,0xa2dbbaca,0xe69a,0x4994,0xb9,0x84,0xf5,0x09,0xf9,0xec,0x35,0x37);


MIDL_DEFINE_GUID(IID, IID_IAtlObject,0x58ae78a0,0xdcff,0x4a4f,0xbe,0x19,0x91,0x53,0xfe,0xe5,0x1d,0xa3);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



