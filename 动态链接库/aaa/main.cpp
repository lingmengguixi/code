// aaa.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
extern Fun fun[200];
int main()
{
	readFunFromFile("1.txt", "2.txt");
	int count=init("2.txt");
	writeAsReadAddr("3.txt");
	writeAsBindVarToFun("4.txt");
	printf("count=%d\n", count);

	system("pause");
}
 