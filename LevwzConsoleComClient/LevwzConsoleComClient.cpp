// LevwzConsoleComClient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <objbase.h>

#include "CTcpIp.h"
#include <iostream>
#include <atlbase.h>
#include <atlcom.h>
using namespace std;
int main()
{

	CTcpIp tcpip;
	tcpip.Test();
    return 0;
}

