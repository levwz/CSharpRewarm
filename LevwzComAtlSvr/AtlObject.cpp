// AtlObject.cpp: CAtlObject 的实现

#include "stdafx.h"
#include "AtlObject.h"


// CAtlObject



STDMETHODIMP CAtlObject::Add(LONG para1, LONG para2, LONG* result)
{
	// TODO: 在此添加实现代码

	if (result == NULL) {
		result = new LONG;
	}

	*result = para1 + para2;

	return S_OK;
}
