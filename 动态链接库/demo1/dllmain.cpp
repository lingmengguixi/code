// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
int first=1;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

	if (first != 1) {
		return true;
	}
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
	first = 0;
	int x = MessageBox(GetForegroundWindow(), L"【调用我的dll啦】", L"【demo】", 1);
    return TRUE;
}

