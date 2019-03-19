#pragma once
#include <vector>
#include <string>
using std::vector;
struct Fun {
	char return_var[100];
	char return_name[100];
	char var[30][100];
	char name[30][100];
	int len = 0;
};
vector<char*> readOkFun();
int init();
Fun *getFunByName(char *name, int count);
int isSpace(char c);