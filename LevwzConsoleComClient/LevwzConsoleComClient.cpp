// LevwzConsoleComClient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <objbase.h>
#include "../LevwzComAtlSvr/LevwzComAtlSvr_i.h"
#include "../LevwzComAtlSvr/LevwzComAtlSvr_i.c"
#include <iostream>
#include <atlbase.h>
#include <atlcom.h>
using namespace std;
int main()
{
	CoInitialize(NULL);
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

