#pragma once
#include <ws2tcpip.h>
#include <windows.h>
HMODULE hModule = NULL;//模块句柄
char buffer[1000];//缓冲区
FARPROC proc;//函数入口指针

SOCKET  (__stdcall *accept1)(SOCKET   s,
	sockaddr *addr,
	int      *addrlen);
BOOL (__stdcall *AcceptEx1)(SOCKET  sListenSocket,
	SOCKET       sAcceptSocket,
	PVOID        lpOutputBuffer,
	DWORD        dwReceiveDataLength,
	DWORD        dwLocalAddressLength,
	DWORD        dwRemoteAddressLength,
	LPDWORD      lpdwBytesReceived,
	LPOVERLAPPED lpOverlapped);
int (__stdcall *bind1)(SOCKET         s,
	const sockaddr *addr,
	int            namelen);
int (__stdcall *closesocket1)(IN SOCKET s);
int (__stdcall *connect1)(SOCKET         s,
	const sockaddr *name,
	int            namelen);
BOOL(__stdcall *ConnectEx1)(SOCKET s,
	const sockaddr *name,
	int namelen,
	PVOID lpSendBuffer,
	DWORD dwSendDataLength,
	LPDWORD lpdwBytesSent,
	LPOVERLAPPED lpOverlapped);
BOOL(__stdcall *DisconnectEx1)(_In_ SOCKET       hSocket,
	_In_ LPOVERLAPPED lpOverlapped,
	_In_ DWORD        dwFlags,
	_In_ DWORD        reserved);
INT(__stdcall *EnumProtocols1)(LPINT   lpiProtocols,
	LPVOID  lpProtocolBuffer,
	LPDWORD lpdwBufferLength);
VOID(__stdcall *freeaddrinfo1)(PADDRINFOA pAddrInfo);
VOID(__stdcall *FreeAddrInfoEx1)(PADDRINFOEXA pAddrInfoEx);
VOID (__stdcall *FreeAddrInfoW1)(PADDRINFOW pAddrInfo);
char * (__stdcall *gai_strerror1)(int ecode);
void(__stdcall *GetAcceptExSockaddrs1)(PVOID    lpOutputBuffer,
	DWORD    dwReceiveDataLength,
	DWORD    dwLocalAddressLength,
	DWORD    dwRemoteAddressLength,
	sockaddr **LocalSockaddr,
	LPINT    LocalSockaddrLength,
	sockaddr **RemoteSockaddr,
	LPINT    RemoteSockaddrLength);
INT(__stdcall *GetAddressByName1)(DWORD                dwNameSpace,
	LPGUID               lpServiceType,
	LPSTR                lpServiceName,
	LPINT                lpiProtocols,
	DWORD                dwResolution,
	LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
	LPVOID               lpCsaddrBuffer,
	LPDWORD              lpdwBufferLength,
	LPSTR                lpAliasBuffer,
	LPDWORD              lpdwAliasBufferLength);
INT(__stdcall *getaddrinfo1)(PCSTR           pNodeName,
	PCSTR           pServiceName,
	const ADDRINFOA *pHints,
	PADDRINFOA      *ppResult);
INT(__stdcall *GetAddrInfoEx1)(PCSTR                              pName,
	PCSTR                              pServiceName,
	DWORD                              dwNameSpace,
	LPGUID                             lpNspId,
	const ADDRINFOEXA                  *hints,
	PADDRINFOEXA                       *ppResult,
	timeval                            *timeout,
	LPOVERLAPPED                       lpOverlapped,
	LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine,
	LPHANDLE                           lpNameHandle);
INT(__stdcall *GetAddrInfoExCancel1)(LPHANDLE lpHandle);
INT(__stdcall *GetAddrInfoExOverlappedResult1)(LPOVERLAPPED lpOverlapped);
INT(__stdcall *GetAddrInfoW1)(PCWSTR          pNodeName,
	PCWSTR          pServiceName,
	const ADDRINFOW *pHints,
	PADDRINFOW      *ppResult);
VOID(__stdcall *gethostbyaddr1)(a,
	b,
	c);
(__stdcall *gethostbyname1)();
(__stdcall *gethostname1)();
(__stdcall *GetHostNameW1)();
(__stdcall *getipv4sourcefilter1)();
(__stdcall *GetNameByType1)();
(__stdcall *getnameinfo1)();
(__stdcall *GetNameInfoW1)();
(__stdcall *getpeername1)();
(__stdcall *getprotobyname1)();
(__stdcall *getprotobynumber1)();
(__stdcall *getservbyname1)();
(__stdcall *getservbyport1)();
(__stdcall *GetService1)();
(__stdcall *getsockname1)();
(__stdcall *getsockopt1)();
(__stdcall *getsourcefilter1)();
(__stdcall *GetTypeByName1)();
(__stdcall *htond1)();
(__stdcall *htonf1)();
(__stdcall *htonl1)();
(__stdcall *htonll1)();
(__stdcall *htons1)();
(__stdcall *inet_addr1)();
(__stdcall *inet_ntoa1)();
(__stdcall *InetNtop1)();
(__stdcall *InetPton1)();
(__stdcall *ioctlsocket1)();
(__stdcall *listen1)();
(__stdcall *ntohd1)();
(__stdcall *ntohf1)();
(__stdcall *ntohl1)();
(__stdcall *ntohll1)();
(__stdcall *ntohs1)();
(__stdcall *recv1)();
(__stdcall *recvfrom1)();
(__stdcall *RIOCloseCompletionQueue1)();
(__stdcall *RIOCreateCompletionQueue1)();
(__stdcall *RIOCreateRequestQueue1)();
(__stdcall *RIODequeueCompletion1)();
(__stdcall *RIODeregisterBuffer1)();
(__stdcall *RIONotify1)();
(__stdcall *RIOReceive1)();
(__stdcall *RIOReceiveEx1)();
(__stdcall *RIORegisterBuffer1)();
(__stdcall *RIOResizeCompletionQueue1)();
(__stdcall *RIOResizeRequestQueue1)();
(__stdcall *RIOSend1)();
(__stdcall *RIOSendEx1)();
(__stdcall *send1)();
(__stdcall *sendto1)();
(__stdcall *SetAddrInfoEx1)();
(__stdcall *setipv4sourcefilter1)();
(__stdcall *SetService1)();
(__stdcall *SetSocketMediaStreamingMode1)();
(__stdcall *setsockopt1)();
(__stdcall *setsourcefilter1)();
(__stdcall *shutdown1)();
(__stdcall *TransmitFile1)();
(__stdcall *TransmitPackets1)();
(__stdcall *WSAAccept1)();
(__stdcall *WSAAddressToString1)();
(__stdcall *WSAAsyncGetHostByAddr1)();
(__stdcall *WSAAsyncGetHostByName1)();
(__stdcall *WSAAsyncGetProtoByName1)();
(__stdcall *WSAAsyncGetProtoByNumber1)();
(__stdcall *WSAAsyncGetServByName1)();
(__stdcall *WSAAsyncGetServByPort1)();
(__stdcall *WSAAsyncSelect1)();
(__stdcall *WSACancelAsyncRequest1)();
(__stdcall *WSACleanup1)();
(__stdcall *WSACloseEvent1)();
(__stdcall *WSAConnect1)();
(__stdcall *WSAConnectByList1)();
(__stdcall *WSAConnectByName1)();
(__stdcall *WSACreateEvent1)();
(__stdcall *WSADeleteSocketPeerTargetName1)();
(__stdcall *WSADuplicateSocket1)();
(__stdcall *WSAEnumNameSpaceProviders1)();
(__stdcall *WSAEnumNameSpaceProvidersEx1)();
(__stdcall *WSAEnumNetworkEvents1)();
(__stdcall *WSAEnumProtocols1)();
(__stdcall *WSAEventSelect1)();
(__stdcall *__WSAFDIsSet1)();
(__stdcall *WSAGetLastError1)();
(__stdcall *WSAGetOverlappedResult1)();
(__stdcall *WSAGetQOSByName1)();
(__stdcall *WSAGetServiceClassInfo1)();
(__stdcall *WSAGetServiceClassNameByClassId1)();
(__stdcall *WSAHtonl1)();
(__stdcall *WSAHtons1)();
(__stdcall *WSAImpersonateSocketPeer1)();
(__stdcall *WSAInstallServiceClass1)();
(__stdcall *WSAIoctl1)();
(__stdcall *WSAJoinLeaf1)();
(__stdcall *WSALookupServiceBegin1)();
(__stdcall *WSALookupServiceEnd1)();
(__stdcall *WSALookupServiceNext1)();
(__stdcall *WSANSPIoctl1)();
(__stdcall *WSANtohl1)();
(__stdcall *WSANtohs1)();
(__stdcall *WSAPoll1)();
(__stdcall *WSAProviderConfigChange1)();
(__stdcall *WSAQuerySocketSecurity1)();
(__stdcall *WSARecv1)();
(__stdcall *WSARecvDisconnect1)();
(__stdcall *WSARecvEx1)();
(__stdcall *WSARecvFrom1)();
(__stdcall *WSARecvMsg1)();
(__stdcall *WSARemoveServiceClass1)();
(__stdcall *WSAResetEvent1)();
(__stdcall *WSARevertImpersonation1)();
(__stdcall *WSASend1)();
(__stdcall *WSASendDisconnect1)();
(__stdcall *WSASendMsg1)();
(__stdcall *WSASendTo1)();
(__stdcall *WSASetEvent1)();
(__stdcall *WSASetLastError1)();
(__stdcall *WSASetService1)();
(__stdcall *WSASetSocketPeerTargetName1)();
(__stdcall *WSASetSocketSecurity1)();
(__stdcall *WSASocket1)();
(__stdcall *WSAStartup1)();
(__stdcall *WSAStringToAddress1)();
(__stdcall *WSAWaitForMultipleEvents1)();