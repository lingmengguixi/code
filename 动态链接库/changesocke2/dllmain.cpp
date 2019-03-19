// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "myhead.h"
int first = 1;
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	bool ok=myinit();
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
	if(ok) MessageBox(GetForegroundWindow(), L"【调用我的dll啦】", L"【提示】", 1);
	else {
		int error = GetLastError();
		if (error == 126) {
			MessageBox(GetForegroundWindow(), L"【找不到dll啦:wsock32.001】", L"【提示】", 1);
		}
		else if (error == 193) {
			MessageBox(GetForegroundWindow(), L"【这个dll无效啦:wsock32.001】", L"【提示】", 1);
		}else {
			wchar_t message[1000];
			wsprintf(message, L"【错误码:%d 奇怪的错误?wsock32.001】", GetLastError());
			MessageBox(GetForegroundWindow(), message, L"【提示】", 1);
		}
	}
	return TRUE;
}


