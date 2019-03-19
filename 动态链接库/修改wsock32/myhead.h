#pragma once
#include <vector>
#include <string>
//#include <nspapi.h>
//#include <Ws2spi.h>
//#include <Mswsock.h>
bool myinit();
//1
BOOL(__stdcall *AcceptEx1)(
	SOCKET       sListenSocket,
	SOCKET       sAcceptSocket,
	PVOID        lpOutputBuffer,
	DWORD        dwReceiveDataLength,
	DWORD        dwLocalAddressLength,
	DWORD        dwRemoteAddressLength,
	LPDWORD      lpdwBytesReceived,
	LPOVERLAPPED lpOverlapped
	);
//2
INT(__stdcall *EnumProtocolsA1)(
	LPINT   lpiProtocols,
	LPVOID  lpProtocolBuffer,
	LPDWORD lpdwBufferLength
	);
//3
INT(__stdcall *EnumProtocolsW1)(
	LPINT   lpiProtocols,
	LPVOID  lpProtocolBuffer,
	LPDWORD lpdwBufferLength
);
//4
void(__stdcall *GetAcceptExSockaddrs1)(
	PVOID    lpOutputBuffer,
	DWORD    dwReceiveDataLength,
	DWORD    dwLocalAddressLength,
	DWORD    dwRemoteAddressLength,
	sockaddr **LocalSockaddr,
	LPINT    LocalSockaddrLength,
	sockaddr **RemoteSockaddr,
	LPINT    RemoteSockaddrLength
	);
//5
INT(__stdcall *GetAddressByNameA1)(
	DWORD                dwNameSpace,
	LPGUID               lpServiceType,
	LPSTR                lpServiceName,
	LPINT                lpiProtocols,
	DWORD                dwResolution,
	LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
	LPVOID               lpCsaddrBuffer,
	LPDWORD              lpdwBufferLength,
	LPSTR                lpAliasBuffer,
	LPDWORD              lpdwAliasBufferLength
	);
//6
INT(__stdcall *GetAddressByNameW1)(
	DWORD                dwNameSpace,
	LPGUID               lpServiceType,
	LPWSTR               lpServiceName,
	LPINT                lpiProtocols,
	DWORD                dwResolution,
	LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
	LPVOID               lpCsaddrBuffer,
	LPDWORD              lpdwBufferLength,
	LPWSTR               lpAliasBuffer,
	LPDWORD              lpdwAliasBufferLength
);
