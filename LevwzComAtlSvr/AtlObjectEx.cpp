// AtlObjectEx.cpp: CAtlObjectEx 的实现

#include "stdafx.h"
#include "AtlObjectEx.h"


// CAtlObjectEx



STDMETHODIMP CAtlObjectEx::DoInitSomething(LONG* param1, LONG* param2, LONG* result)
{
	if (param1 == NULL) {
		return E_INVALIDARG;
	}
	*result = *param1 + *param2;
	return S_OK;
}
