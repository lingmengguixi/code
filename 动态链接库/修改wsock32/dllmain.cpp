// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "myhead.h"
/*
AcceptEx @1
EnumProtocolsA @2
EnumProtocolsW @3
GetAcceptExSockaddrs @4
GetAddressByNameA @5
GetAddressByNameW @6
*/
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	myinit();
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

