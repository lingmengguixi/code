// 修改wsock32.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "myhead.h"

HMODULE hModule = NULL; // 模 块句柄
char buffer[1000]; // 缓冲区
FARPROC proc; // 函数入口指针
bool myinit() {
	if (hModule == NULL) {
		// 加载原 WinSock 库，原 WinSock 库已复制为 wsock32.001 。
		hModule = LoadLibrary(L"wsock32.001");

	}
	else return true;
	if (hModule != NULL) {
		////1
		//proc = GetProcAddress(hModule, "AcceptEx");
		//AcceptEx1 = (BOOL(__stdcall *)(SOCKET, SOCKET, PVOID, DWORD, DWORD, DWORD, LPDWORD, LPOVERLAPPED))proc;
		////2
		//proc = GetProcAddress(hModule, "EnumProtocolsA");
		//EnumProtocolsA1 = (INT(__stdcall *)(LPINT, LPVOID, LPDWORD))proc;
		////3
		//proc = GetProcAddress(hModule, "EnumProtocolsW");
		//EnumProtocolsW1 = (INT(__stdcall *)(LPINT, LPVOID, LPDWORD))proc;
  //      //4
		//proc = GetProcAddress(hModule, "GetAcceptExSockaddrs");
		//GetAcceptExSockaddrs1 = (void(__stdcall *)(PVOID, DWORD, DWORD, DWORD, sockaddr **, LPINT, sockaddr **, LPINT))proc;
		////5
		//proc = GetProcAddress(hModule, "GetAddressByNameA");
		//GetAddressByNameA1 = (INT(__stdcall *)(DWORD, LPGUID, LPSTR, LPINT, DWORD, LPSERVICE_ASYNC_INFO, LPVOID, LPDWORD, LPSTR, LPDWORD))proc;
		////6
		//proc = GetProcAddress(hModule, "GetAddressByNameW");
		//GetAddressByNameW1 = (INT(__stdcall *)(DWORD, LPGUID, LPWSTR, LPINT, DWORD, LPSERVICE_ASYNC_INFO, LPVOID, LPDWORD, LPWSTR, LPDWORD))proc;

	}
	else return false;
	return true;
}