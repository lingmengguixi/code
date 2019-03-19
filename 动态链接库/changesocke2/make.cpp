#include "stdafx.h"
#include "myhead.h"
HMODULE hModule = NULL; // 模 块句柄
char buffer[1000]; // 缓冲区
FARPROC proc; // 函数入口指针

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
//7
INT(__stdcall *GetNameByTypeA1)(
	LPGUID lpServiceType,
	LPSTR  lpServiceName,
	DWORD  dwNameLength
	);


INT(__stdcall *GetNameByTypeW1)(
	LPGUID lpServiceType,
	LPWSTR lpServiceName,
	DWORD  dwNameLength
	);
INT(__stdcall *GetServiceA1)(
	DWORD                dwNameSpace,
	LPGUID               lpGuid,
	LPSTR                lpServiceName,
	DWORD                dwProperties,
	LPVOID               lpBuffer,
	LPDWORD              lpdwBufferSize,
	LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
	);
INT(__stdcall *GetServiceW1)(
	DWORD                dwNameSpace,
	LPGUID               lpGuid,
	LPWSTR               lpServiceName,
	DWORD                dwProperties,
	LPVOID               lpBuffer,
	LPDWORD              lpdwBufferSize,
	LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
	);
INT(__stdcall *GetTypeByNameA1)(
	LPSTR  lpServiceName,
	LPGUID lpServiceType
	);
INT(__stdcall *GetTypeByNameW1)(
	LPWSTR lpServiceName,
	LPGUID lpServiceType
	);
INT(__stdcall *SetServiceA1)(
	DWORD                dwNameSpace,
	DWORD                dwOperation,
	DWORD                dwFlags,
	LPSERVICE_INFOA      lpServiceInfo,
	LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
	LPDWORD              lpdwStatusFlags
	);
INT(__stdcall *SetServiceW1)(
	DWORD                dwNameSpace,
	DWORD                dwOperation,
	DWORD                dwFlags,
	LPSERVICE_INFOW      lpServiceInfo,
	LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
	LPDWORD              lpdwStatusFlags
	);
BOOL(__stdcall *TransmitFile1)(
	SOCKET                  hSocket,
	HANDLE                  hFile,
	DWORD                   nNumberOfBytesToWrite,
	DWORD                   nNumberOfBytesPerSend,
	LPOVERLAPPED            lpOverlapped,
	LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers,
	DWORD                   dwReserved
	);
HANDLE(__stdcall *WSAAsyncGetHostByAddr1)(
	HWND       hWnd,
	u_int      wMsg,
	const char *addr,
	int        len,
	int        type,
	char       *buf,
	int        buflen
	);
HANDLE(__stdcall *WSAAsyncGetHostByName1)(
	HWND       hWnd,
	u_int      wMsg,
	const char *name,
	char       *buf,
	int        buflen
	);
HANDLE(__stdcall *WSAAsyncGetProtoByName1)(
	HWND       hWnd,
	u_int      wMsg,
	const char *name,
	char       *buf,
	int        buflen
	);
HANDLE(__stdcall *WSAAsyncGetProtoByNumber1)(
	HWND  hWnd,
	u_int wMsg,
	int   number,
	char  *buf,
	int   buflen
	);
HANDLE(__stdcall *WSAAsyncGetServByName1)(
	HWND       hWnd,
	u_int      wMsg,
	const char *name,
	const char *proto,
	char       *buf,
	int        buflen
	);
HANDLE(__stdcall *WSAAsyncGetServByPort1)(
	HWND       hWnd,
	u_int      wMsg,
	int        port,
	const char *proto,
	char       *buf,
	int        buflen
	);
int(__stdcall *WSAAsyncSelect1)(
	SOCKET s,
	HWND   hWnd,
	u_int  wMsg,
	long   lEvent
	);
int(__stdcall *WSACancelAsyncRequest1)(
	HANDLE hAsyncTaskHandle
	);
int(__stdcall *WSACancelBlockingCall1)(

	);
int(__stdcall *WSACleanup1)(

	);
int(__stdcall *WSAGetLastError1)(

	);
BOOL(__stdcall *WSAIsBlocking1)(

	);
int(__stdcall *WSARecvEx1)(
	SOCKET s,
	char   *buf,
	int    len,
	int    *flags
	);
void(__stdcall *WSASetLastError1)(
	int iError
	);
int(__stdcall *WSAStartup1)(
	WORD      wVersionRequired,
	LPWSADATA lpWSAData
	);
int(__stdcall *__WSAFDIsSet1)(
	SOCKET socket,
	fd_set *set1
	);
SOCKET(__stdcall *accept1)(
	SOCKET   s,
	sockaddr *addr,
	int      *addrlen
	);
int(__stdcall *bind1)(
	SOCKET         s,
	const sockaddr *addr,
	int            namelen
	);
int(__stdcall *closesocket1)(
	IN SOCKET s
	);
int(__stdcall *connect1)(
	SOCKET         s,
	const sockaddr *name,
	int            namelen
	);
hostent *  (__stdcall *gethostbyaddr1)(
	const char *addr,
	int        len,
	int        type
	);
hostent * (__stdcall *gethostbyname1)(
	const char *name
	);
int(__stdcall *gethostname1)(
	char *name,
	int  namelen
	);
int(__stdcall *getpeername1)(
	SOCKET   s,
	sockaddr *name,
	int      *namelen
	);
protoent * (__stdcall *getprotobyname1)(
	const char *name
	);
protoent * (__stdcall *getprotobynumber1)(
	int proto
	);
servent * (__stdcall *getservbyname1)(
	const char *name,
	const char *proto
	);
servent * (__stdcall *getservbyport1)(
	int        port,
	const char *proto
	);
int(__stdcall *getsockname1)(
	SOCKET   s,
	sockaddr *name,
	int      *namelen
	);
int(__stdcall *getsockopt1)(
	SOCKET s,
	int    level,
	int    optname,
	char   *optval,
	int    *optlen
	);
u_long(__stdcall *htonl1)(
	u_long hostlong
	);
u_short(__stdcall *htons1)(
	u_short hostshort
	);
unsigned long(__stdcall *inet_addr1)(
	const char *cp
	);
char * (__stdcall *inet_ntoa1)(
	in_addr in
	);
int(__stdcall *ioctlsocket1)(
	SOCKET s,
	long   cmd,
	u_long *argp
	);
int(__stdcall *listen1)(
	SOCKET s,
	int    backlog
	);
u_long(__stdcall *ntohl1)(
	u_long netlong
	);
u_short(__stdcall *ntohs1)(
	u_short netshort
	);
int(__stdcall *recv1)(
	SOCKET s,
	char   *buf,
	int    len,
	int    flags
	);
int(__stdcall *recvfrom1)(
	SOCKET   s,
	char     *buf,
	int      len,
	int      flags,
	sockaddr *from,
	int      *fromlen
	);
int(__stdcall *select1)(
	int           nfds,
	fd_set        *readfds,
	fd_set        *writefds,
	fd_set        *exceptfds,
	const timeval *timeout
	);
int(__stdcall *send1)(
	SOCKET     s,
	const char *buf,
	int        len,
	int        flags
	);
int(__stdcall *sendto1)(
	SOCKET         s,
	const char     *buf,
	int            len,
	int            flags,
	const sockaddr *to,
	int            tolen
	);
int(__stdcall *setsockopt1)(
	SOCKET     s,
	int        level,
	int        optname,
	const char *optval,
	int        optlen
	);
int(__stdcall *shutdown1)(
	SOCKET s,
	int    how
	);
SOCKET(__stdcall *socket1)(
	int af,
	int type,
	int protocol
	);
//1
BOOL PASCAL FAR AcceptEx(SOCKET sListenSocket, SOCKET sAcceptSocket, PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, LPDWORD lpdwBytesReceived, LPOVERLAPPED lpOverlapped) {
	return AcceptEx1(sListenSocket, sAcceptSocket, lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, lpdwBytesReceived, lpOverlapped);
}
//2
INT PASCAL FAR EnumProtocolsA(LPINT lpiProtocols, LPVOID lpProtocolBuffer, LPDWORD lpdwBufferLength) {
	return EnumProtocolsA1(lpiProtocols, lpProtocolBuffer, lpdwBufferLength);
}
//3
INT PASCAL FAR EnumProtocolsW(LPINT lpiProtocols, LPVOID  lpProtocolBuffer, LPDWORD lpdwBufferLength) {
	return EnumProtocolsW(lpiProtocols, lpProtocolBuffer,lpdwBufferLength);
}

//4
void PASCAL FAR GetAcceptExSockaddrs(PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, sockaddr ** LocalSockaddr, LPINT LocalSockaddrLength, sockaddr ** RemoteSockaddr, LPINT RemoteSockaddrLength) {
	return GetAcceptExSockaddrs1(lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, LocalSockaddr, LocalSockaddrLength, RemoteSockaddr, RemoteSockaddrLength);
}
//5
INT PASCAL FAR GetAddressByNameA(DWORD dwNameSpace, LPGUID lpServiceType, LPSTR lpServiceName, LPINT lpiProtocols, DWORD dwResolution, LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, LPVOID lpCsaddrBuffer, LPDWORD lpdwBufferLength, LPSTR lpAliasBuffer, LPDWORD lpdwAliasBufferLength) {
	return GetAddressByNameA1(dwNameSpace, lpServiceType, lpServiceName, lpiProtocols, dwResolution, lpServiceAsyncInfo, lpCsaddrBuffer, lpdwBufferLength, lpAliasBuffer, lpdwAliasBufferLength);
}
//6
INT PASCAL FAR GetAddressByNameW(DWORD dwNameSpace,LPGUID lpServiceType,LPWSTR lpServiceName,LPINT lpiProtocols,DWORD dwResolution,LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,LPVOID lpCsaddrBuffer,LPDWORD lpdwBufferLength,LPWSTR lpAliasBuffer,LPDWORD lpdwAliasBufferLength){
	return GetAddressByNameW1(dwNameSpace, lpServiceType, lpServiceName, lpiProtocols, dwResolution, lpServiceAsyncInfo, lpCsaddrBuffer, lpdwBufferLength, lpAliasBuffer, lpdwAliasBufferLength);
}
//7
INT PASCAL FAR GetNameByTypeA(LPGUID lpServiceType, LPSTR lpServiceName, DWORD dwNameLength) {
	return GetNameByTypeA1(lpServiceType, lpServiceName, dwNameLength);
}
INT  PASCAL FAR GetNameByTypeW(LPGUID lpServiceType, LPWSTR lpServiceName, DWORD dwNameLength) {
	return GetNameByTypeW1(lpServiceType, lpServiceName, dwNameLength);
}
INT  PASCAL FAR GetServiceA(DWORD dwNameSpace, LPGUID lpGuid, LPSTR lpServiceName, DWORD dwProperties, LPVOID lpBuffer, LPDWORD lpdwBufferSize, LPSERVICE_ASYNC_INFO lpServiceAsyncInfo) {
	return GetServiceA1(dwNameSpace, lpGuid, lpServiceName, dwProperties, lpBuffer, lpdwBufferSize, lpServiceAsyncInfo);
}
INT  PASCAL FAR GetServiceW(DWORD dwNameSpace, LPGUID lpGuid, LPWSTR lpServiceName, DWORD dwProperties, LPVOID lpBuffer, LPDWORD lpdwBufferSize, LPSERVICE_ASYNC_INFO lpServiceAsyncInfo) {
	return GetServiceW1(dwNameSpace, lpGuid, lpServiceName, dwProperties, lpBuffer, lpdwBufferSize, lpServiceAsyncInfo);
}
INT  PASCAL FAR GetTypeByNameA(LPSTR lpServiceName, LPGUID lpServiceType) {
	return GetTypeByNameA1(lpServiceName, lpServiceType);
}
INT  PASCAL FAR GetTypeByNameW(LPWSTR lpServiceName, LPGUID lpServiceType) {
	return GetTypeByNameW1(lpServiceName, lpServiceType);
}
INT  PASCAL FAR SetServiceA(DWORD dwNameSpace, DWORD dwOperation, DWORD dwFlags, LPSERVICE_INFOA lpServiceInfo, LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, LPDWORD lpdwStatusFlags) {
	return SetServiceA1(dwNameSpace, dwOperation, dwFlags, lpServiceInfo, lpServiceAsyncInfo, lpdwStatusFlags);
}
INT  PASCAL FAR SetServiceW(DWORD dwNameSpace, DWORD dwOperation, DWORD dwFlags, LPSERVICE_INFOW lpServiceInfo, LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, LPDWORD lpdwStatusFlags) {
	return SetServiceW1(dwNameSpace, dwOperation, dwFlags, lpServiceInfo, lpServiceAsyncInfo, lpdwStatusFlags);
}
BOOL  PASCAL FAR TransmitFile(SOCKET hSocket, HANDLE hFile, DWORD nNumberOfBytesToWrite, DWORD nNumberOfBytesPerSend, LPOVERLAPPED lpOverlapped, LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers, DWORD dwReserved) {
	return TransmitFile1(hSocket, hFile, nNumberOfBytesToWrite, nNumberOfBytesPerSend, lpOverlapped, lpTransmitBuffers, dwReserved);
}
HANDLE  PASCAL FAR WSAAsyncGetHostByAddr(HWND hWnd, u_int wMsg, const char * addr, int len, int type, char * buf, int buflen) {
	return WSAAsyncGetHostByAddr1(hWnd, wMsg, addr, len, type, buf, buflen);
}
HANDLE  PASCAL FAR WSAAsyncGetHostByName(HWND hWnd, u_int wMsg, const char * name, char * buf, int buflen) {
	return WSAAsyncGetHostByName1(hWnd, wMsg, name, buf, buflen);
}
HANDLE  PASCAL FAR WSAAsyncGetProtoByName(HWND hWnd, u_int wMsg, const char * name, char * buf, int buflen) {
	return WSAAsyncGetProtoByName1(hWnd, wMsg, name, buf, buflen);
}
HANDLE  PASCAL FAR WSAAsyncGetProtoByNumber(HWND hWnd, u_int wMsg, int number, char * buf, int buflen) {
	return WSAAsyncGetProtoByNumber1(hWnd, wMsg, number, buf, buflen);
}
HANDLE  PASCAL FAR WSAAsyncGetServByName(HWND hWnd, u_int wMsg, const char * name, const char * proto, char * buf, int buflen) {
	return WSAAsyncGetServByName1(hWnd, wMsg, name, proto, buf, buflen);
}
HANDLE  PASCAL FAR WSAAsyncGetServByPort(HWND hWnd, u_int wMsg, int port, const char * proto, char * buf, int buflen) {
	return WSAAsyncGetServByPort1(hWnd, wMsg, port, proto, buf, buflen);
}
int  PASCAL FAR WSAAsyncSelect(SOCKET s, HWND hWnd, u_int wMsg, long lEvent) {
	return WSAAsyncSelect1(s, hWnd, wMsg, lEvent);
}
int  PASCAL FAR WSACancelAsyncRequest(HANDLE hAsyncTaskHandle) {
	return WSACancelAsyncRequest1(hAsyncTaskHandle);
}
int  PASCAL FAR WSACancelBlockingCall() {
	return WSACancelBlockingCall1();
}
int  PASCAL FAR WSACleanup() {
	return WSACleanup1();
}
int  PASCAL FAR WSAGetLastError() {
	return WSAGetLastError1();
}
BOOL  PASCAL FAR WSAIsBlocking() {
	return WSAIsBlocking1();
}
int  PASCAL FAR WSARecvEx(SOCKET s, char * buf, int len, int * flags) {
	return WSARecvEx1(s, buf, len, flags);
}
void  PASCAL FAR WSASetLastError(int iError) {
	return WSASetLastError1(iError);
}
int  PASCAL FAR WSAStartup(WORD wVersionRequired, LPWSADATA lpWSAData) {
	return WSAStartup1(wVersionRequired, lpWSAData);
}
int  PASCAL FAR __WSAFDIsSet(SOCKET socket, fd_set * set1) {
	return __WSAFDIsSet1(socket, set1);
}
SOCKET  PASCAL FAR accept(SOCKET s, sockaddr * addr, int * addrlen) {
	return accept1(s, addr, addrlen);
}
int  PASCAL FAR bind(SOCKET s, const sockaddr * addr, int namelen) {
	return bind1(s, addr, namelen);
}
int  PASCAL FAR closesocket(IN SOCKET s) {
	return closesocket1(s);
}
int  PASCAL FAR connect(SOCKET s, const sockaddr * name, int namelen) {
	return connect1(s, name, namelen);
}
hostent *  PASCAL FAR gethostbyaddr(const char * addr, int len, int type) {
	return gethostbyaddr1(addr, len, type);
}
hostent *  PASCAL FAR gethostbyname(const char * name) {
	return gethostbyname1(name);
}
int  PASCAL FAR gethostname(char * name, int namelen) {
	return gethostname1(name, namelen);
}
int  PASCAL FAR getpeername(SOCKET s, sockaddr * name, int * namelen) {
	return getpeername1(s, name, namelen);
}
protoent *  PASCAL FAR getprotobyname(const char * name) {
	return getprotobyname1(name);
}
protoent *  PASCAL FAR getprotobynumber(int proto) {
	return getprotobynumber1(proto);
}
servent *  PASCAL FAR getservbyname(const char * name, const char * proto) {
	return getservbyname1(name, proto);
}
servent *  PASCAL FAR getservbyport(int port, const char * proto) {
	return getservbyport1(port, proto);
}
int  PASCAL FAR getsockname(SOCKET s, sockaddr * name, int * namelen) {
	return getsockname1(s, name, namelen);
}
int  PASCAL FAR getsockopt(SOCKET s, int level, int optname, char * optval, int * optlen) {
	return getsockopt1(s, level, optname, optval, optlen);
}
u_long  PASCAL FAR htonl(u_long hostlong) {
	return htonl1(hostlong);
}
u_short  PASCAL FAR htons(u_short hostshort) {
	return htons1(hostshort);
}
unsigned long  PASCAL FAR inet_addr(const char * cp) {
	return inet_addr1(cp);
}
char *  PASCAL FAR inet_ntoa(in_addr in) {
	return inet_ntoa1(in);
}
int  PASCAL FAR ioctlsocket(SOCKET s, long cmd, u_long * argp) {
	return ioctlsocket1(s, cmd, argp);
}
int  PASCAL FAR listen(SOCKET s, int backlog) {
	return listen1(s, backlog);
}
u_long  PASCAL FAR ntohl(u_long netlong) {
	return ntohl1(netlong);
}
u_short  PASCAL FAR ntohs(u_short netshort) {
	return ntohs1(netshort);
}
int  PASCAL FAR recv(SOCKET s, char * buf, int len, int flags) {
	return recv1(s, buf, len, flags);
}
int  PASCAL FAR recvfrom(SOCKET s, char * buf, int len, int flags, sockaddr * from, int * fromlen) {
	return recvfrom1(s, buf, len, flags, from, fromlen);
}
int  PASCAL FAR select(int nfds, fd_set * readfds, fd_set * writefds, fd_set * exceptfds, const timeval * timeout) {
	return select1(nfds, readfds, writefds, exceptfds, timeout);
}
int  PASCAL FAR send(SOCKET s, const char * buf, int len, int flags) {
	return send1(s, buf, len, flags);
}
int  PASCAL FAR sendto(SOCKET s, const char * buf, int len, int flags, const sockaddr * to, int tolen) {
	return sendto1(s, buf, len, flags, to, tolen);
}
int  PASCAL FAR setsockopt(SOCKET s, int level, int optname, const char * optval, int optlen) {
	return setsockopt1(s, level, optname, optval, optlen);
}
int  PASCAL FAR shutdown(SOCKET s, int how) {
	return shutdown1(s, how);
}
SOCKET  PASCAL FAR socket(int af, int type, int protocol) {
	return socket1(af, type, protocol);
}

bool myinit() {
	if (hModule == NULL) {
		// 加载原 WinSock 库，原 WinSock 库已复制为 wsock32.001 。
		hModule = LoadLibrary(L"C:\\Windows\\System32\\wsock32.dll");
	}
	else return true;
	if (hModule != NULL) {

		//1
		proc = GetProcAddress(hModule, "AcceptEx");
		AcceptEx1 = (BOOL(__stdcall *)(SOCKET, SOCKET, PVOID, DWORD, DWORD, DWORD, LPDWORD, LPOVERLAPPED))proc;
		//2
		proc = GetProcAddress(hModule, "EnumProtocolsA");
		EnumProtocolsA1 = (INT(__stdcall *)(LPINT, LPVOID, LPDWORD))proc;
		//3
		proc = GetProcAddress(hModule, "EnumProtocolsW");
		EnumProtocolsW1 = (INT(__stdcall *)(LPINT, LPVOID, LPDWORD))proc;
		//4
		proc = GetProcAddress(hModule, "GetAcceptExSockaddrs");
		GetAcceptExSockaddrs1 = (void(__stdcall *)(PVOID, DWORD, DWORD, DWORD, sockaddr **, LPINT, sockaddr **, LPINT))proc;
		//5
		proc = GetProcAddress(hModule, "GetAddressByNameA");
		GetAddressByNameA1 = (INT(__stdcall *)(DWORD, LPGUID, LPSTR, LPINT, DWORD, LPSERVICE_ASYNC_INFO, LPVOID, LPDWORD, LPSTR, LPDWORD))proc;
		//6
		proc = GetProcAddress(hModule, "GetAddressByNameW");
		GetAddressByNameW1 = (INT(__stdcall *)(DWORD, LPGUID, LPWSTR, LPINT, DWORD, LPSERVICE_ASYNC_INFO, LPVOID, LPDWORD, LPWSTR, LPDWORD))proc;
		//7
		GetNameByTypeA1 = (INT(__stdcall *)(LPGUID, LPSTR, DWORD))proc;
		proc = GetProcAddress(hModule, "getnameinfo");
		proc = GetProcAddress(hModule, "GetNameByTypeW");
		GetNameByTypeW1 = (INT(__stdcall *)(LPGUID, LPWSTR, DWORD))proc;
		proc = GetProcAddress(hModule, "GetServiceA");
		GetServiceA1 = (INT(__stdcall *)(DWORD, LPGUID, LPSTR, DWORD, LPVOID, LPDWORD, LPSERVICE_ASYNC_INFO))proc;
		proc = GetProcAddress(hModule, "GetServiceW");
		GetServiceW1 = (INT(__stdcall *)(DWORD, LPGUID, LPWSTR, DWORD, LPVOID, LPDWORD, LPSERVICE_ASYNC_INFO))proc;
		proc = GetProcAddress(hModule, "GetTypeByNameA");
		GetTypeByNameA1 = (INT(__stdcall *)(LPSTR, LPGUID))proc;
		proc = GetProcAddress(hModule, "GetTypeByNameW");
		GetTypeByNameW1 = (INT(__stdcall *)(LPWSTR, LPGUID))proc;
		proc = GetProcAddress(hModule, "SetServiceA");
		SetServiceA1 = (INT(__stdcall *)(DWORD, DWORD, DWORD, LPSERVICE_INFOA, LPSERVICE_ASYNC_INFO, LPDWORD))proc;
		proc = GetProcAddress(hModule, "SetServiceW");
		SetServiceW1 = (INT(__stdcall *)(DWORD, DWORD, DWORD, LPSERVICE_INFOW, LPSERVICE_ASYNC_INFO, LPDWORD))proc;
		proc = GetProcAddress(hModule, "TransmitFile");
		TransmitFile1 = (BOOL(__stdcall *)(SOCKET, HANDLE, DWORD, DWORD, LPOVERLAPPED, LPTRANSMIT_FILE_BUFFERS, DWORD))proc;
		proc = GetProcAddress(hModule, "WSAAsyncGetHostByAddr");
		WSAAsyncGetHostByAddr1 = (HANDLE(__stdcall *)(HWND, u_int, const char *, int, int, char *, int))proc;
		proc = GetProcAddress(hModule, "WSAAsyncGetHostByName");
		WSAAsyncGetHostByName1 = (HANDLE(__stdcall *)(HWND, u_int, const char *, char *, int))proc;
		proc = GetProcAddress(hModule, "WSAAsyncGetProtoByName");
		WSAAsyncGetProtoByName1 = (HANDLE(__stdcall *)(HWND, u_int, const char *, char *, int))proc;
		proc = GetProcAddress(hModule, "WSAAsyncGetProtoByNumber");
		WSAAsyncGetProtoByNumber1 = (HANDLE(__stdcall *)(HWND, u_int, int, char *, int))proc;
		proc = GetProcAddress(hModule, "WSAAsyncGetServByName");
		WSAAsyncGetServByName1 = (HANDLE(__stdcall *)(HWND, u_int, const char *, const char *, char *, int))proc;
		proc = GetProcAddress(hModule, "WSAAsyncGetServByPort");
		WSAAsyncGetServByPort1 = (HANDLE(__stdcall *)(HWND, u_int, int, const char *, char *, int))proc;
		proc = GetProcAddress(hModule, "WSAAsyncSelect");
		WSAAsyncSelect1 = (int(__stdcall *)(SOCKET, HWND, u_int, long))proc;
		proc = GetProcAddress(hModule, "WSACancelAsyncRequest");
		WSACancelAsyncRequest1 = (int(__stdcall *)(HANDLE))proc;
		proc = GetProcAddress(hModule, "WSACancelBlockingCall");
		WSACancelBlockingCall1 = (int(__stdcall *)())proc;
		proc = GetProcAddress(hModule, "WSACleanup");
		WSACleanup1 = (int(__stdcall *)())proc;
		proc = GetProcAddress(hModule, "WSAGetLastError");
		WSAGetLastError1 = (int(__stdcall *)())proc;
		proc = GetProcAddress(hModule, "WSAIsBlocking");
		WSAIsBlocking1 = (BOOL(__stdcall *)())proc;
		proc = GetProcAddress(hModule, "WSARecvEx");
		WSARecvEx1 = (int(__stdcall *)(SOCKET, char *, int, int *))proc;
		proc = GetProcAddress(hModule, "WSASetLastError");
		WSASetLastError1 = (void(__stdcall *)(int))proc;
		proc = GetProcAddress(hModule, "WSAStartup");
		WSAStartup1 = (int(__stdcall *)(WORD, LPWSADATA))proc;
		proc = GetProcAddress(hModule, "__WSAFDIsSet");
		__WSAFDIsSet1 = (int(__stdcall *)(SOCKET, fd_set *))proc;
		proc = GetProcAddress(hModule, "accept");
		accept1 = (SOCKET(__stdcall *)(SOCKET, sockaddr *, int *))proc;
		proc = GetProcAddress(hModule, "bind");
		bind1 = (int(__stdcall *)(SOCKET, const sockaddr *, int))proc;
		proc = GetProcAddress(hModule, "closesocket");
		closesocket1 = (int(__stdcall *)(IN SOCKET))proc;
		proc = GetProcAddress(hModule, "connect");
		connect1 = (int(__stdcall *)(SOCKET, const sockaddr *, int))proc;
		proc = GetProcAddress(hModule, "gethostbyaddr");
		gethostbyaddr1 = (hostent * (__stdcall *)(const char *, int, int))proc;
		proc = GetProcAddress(hModule, "gethostbyname");
		gethostbyname1 = (hostent * (__stdcall *)(const char *))proc;
		proc = GetProcAddress(hModule, "gethostname");
		gethostname1 = (int(__stdcall *)(char *, int))proc;
		proc = GetProcAddress(hModule, "getpeername");
		getpeername1 = (int(__stdcall *)(SOCKET, sockaddr *, int *))proc;
		proc = GetProcAddress(hModule, "getprotobyname");
		getprotobyname1 = (protoent * (__stdcall *)(const char *))proc;
		proc = GetProcAddress(hModule, "getprotobynumber");
		getprotobynumber1 = (protoent * (__stdcall *)(int))proc;
		proc = GetProcAddress(hModule, "getservbyname");
		getservbyname1 = (servent * (__stdcall *)(const char *, const char *))proc;
		proc = GetProcAddress(hModule, "getservbyport");
		getservbyport1 = (servent * (__stdcall *)(int, const char *))proc;
		proc = GetProcAddress(hModule, "getsockname");
		getsockname1 = (int(__stdcall *)(SOCKET, sockaddr *, int *))proc;
		proc = GetProcAddress(hModule, "getsockopt");
		getsockopt1 = (int(__stdcall *)(SOCKET, int, int, char *, int *))proc;
		proc = GetProcAddress(hModule, "htonl");
		htonl1 = (u_long(__stdcall *)(u_long))proc;
		proc = GetProcAddress(hModule, "htons");
		htons1 = (u_short(__stdcall *)(u_short))proc;
		proc = GetProcAddress(hModule, "inet_addr");
		inet_addr1 = (unsigned long(__stdcall *)(const char *))proc;
		proc = GetProcAddress(hModule, "inet_ntoa");
		inet_ntoa1 = (char * (__stdcall *)(in_addr))proc;
		proc = GetProcAddress(hModule, "ioctlsocket");
		ioctlsocket1 = (int(__stdcall *)(SOCKET, long, u_long *))proc;
		proc = GetProcAddress(hModule, "listen");
		listen1 = (int(__stdcall *)(SOCKET, int))proc;
		proc = GetProcAddress(hModule, "ntohl");
		ntohl1 = (u_long(__stdcall *)(u_long))proc;
		proc = GetProcAddress(hModule, "ntohs");
		ntohs1 = (u_short(__stdcall *)(u_short))proc;
		proc = GetProcAddress(hModule, "recv");
		recv1 = (int(__stdcall *)(SOCKET, char *, int, int))proc;
		proc = GetProcAddress(hModule, "recvfrom");
		recvfrom1 = (int(__stdcall *)(SOCKET, char *, int, int, sockaddr *, int *))proc;
		proc = GetProcAddress(hModule, "select");
		select1 = (int(__stdcall *)(int, fd_set *, fd_set *, fd_set *, const timeval *))proc;
		proc = GetProcAddress(hModule, "send");
		send1 = (int(__stdcall *)(SOCKET, const char *, int, int))proc;
		proc = GetProcAddress(hModule, "sendto");
		sendto1 = (int(__stdcall *)(SOCKET, const char *, int, int, const sockaddr *, int))proc;
		proc = GetProcAddress(hModule, "setsockopt");
		setsockopt1 = (int(__stdcall *)(SOCKET, int, int, const char *, int))proc;
		proc = GetProcAddress(hModule, "shutdown");
		shutdown1 = (int(__stdcall *)(SOCKET, int))proc;
		proc = GetProcAddress(hModule, "socket");
		socket1 = (SOCKET(__stdcall *)(int, int, int))proc;

	}
	else return false;
	return true;
}
int haha() {
	return 1000;
}