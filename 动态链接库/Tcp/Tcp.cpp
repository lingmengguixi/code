// Tcp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

int main()
{
	int x;
	x = MessageBox(GetForegroundWindow(), L"【标题】", L"【要说的话】", 1);
	printf("%d\n", x);
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}
	while (true) {
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}
		
		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(80);
		serAddr.sin_addr.S_un.S_addr = inet_addr("14.215.177.39");
		if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) {
			  //连接失败 
				printf("connect error !");
				closesocket(sclient);
				return 0;
		}
		else {
			printf("connect ok !");
		}
		string data;
		cin >> data;
		const char * sendData;
		sendData = data.c_str();
		send(sclient, sendData, strlen(sendData), 0);
		//send()用来将数据由指定的socket传给对方主机
		//int send(int s, const void * msg, int len, unsigned int flags)
		//s为已建立好连接的socket，msg指向数据内容，len则为数据长度，参数flags一般设0
		//成功则返回实际传送出去的字符数，失败返回-1，错误原因存于error 

		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret>0) {
			recData[ret] = 0x00;
			printf(recData);
		}
		closesocket(sclient);
	}
	WSACleanup();
    return 0;
}

