
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef PCH_H
#define PCH_H

#endif //PCH_H
struct Fun {
	char return_var[100];
	char return_name[100];
	char var[30][100];
	char name[30][100];
	int len = 0;
};
int readFunFromFile(const char *fileName, const char *toFileName);
int isSpace(char c);
int init(const char *fileName);
void readArgs(char *s, Fun &fun);
void writeAsReadAddr(const char *fileName);
void writeAsBindVarToFun(const char *fileName);
void writeAsDef(const char *fileName, int startCode);