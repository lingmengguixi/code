// other.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include "myhead.h"
using namespace std;
using std::vector;
char cache[100000];
Fun fun[211];
int p = 0;
vector<char *> readOkFun() {
	FILE *file = fopen("mytxt.txt", "r");
	
	char ss[1000];
	vector<char *> ans;
	if (file == NULL) return ans;
	while (1) {
		char *s = fgets(ss, 1000, file);
		if (s == NULL) {
			break;
		}
		char *p2 = ss + 26;
		ans.push_back(cache + p);
		while (*p2 != '('&&*p2!=0&&!isSpace(*p2)) {
			cache[p++] = *p2;
			p2++;
		}
		cache[p++] = 0;
	}
	fclose(file);
	return ans;
}
int isSpace(char c) {
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r') return 1;
	return 0;
}
void read(char *s, Fun &fun) {
	while (isSpace(*s)) s++;
	int p = 0;
	int t = 0;
	while (*s != '(') {
		fun.return_var[t++] = *s;
		s++;
	}
	fun.return_var[t] = 0;
	s++;
	while (*s != '*') s++;
	s++;
	while (isSpace(*s)) s++;
	t = 0;
	while (*s != ')') {
		fun.return_name[t++] = *s;
		s++;
	}
	while (isSpace(fun.return_name[t - 1])) t--;
	fun.return_name[t - 1] = 0;
	while (*s != '(') s++;
	s++;
	t = 0;
	while (*s != ')') {
		while (isSpace(*s)) s++;
		if (*s == ')') break;
		t = 0;
		while (*s != ','&&*s != ')') {
			fun.var[fun.len][t++] = *s;
			s++;
		}
		int i;
		for (i = 0; i < t; i++) {
			if (!isSpace(fun.var[fun.len][i])) {
				break;
			}
		}
		if (i >= t) {

		}
		else {
			while (isSpace(fun.var[fun.len][t - 1])) t--;
			fun.var[fun.len][t] = 0;
			while (!isSpace(fun.var[fun.len][t - 1]) && fun.var[fun.len][t - 1] != '*') t--;
			strcpy(fun.name[fun.len], fun.var[fun.len] + t);
			fun.var[fun.len][t] = 0;
			while (isSpace(fun.var[fun.len][t - 1])) t--;
			fun.var[fun.len][t] = 0;
			fun.len++;
		}
		if (*s == ',')s++;
	}
}
int init() {
	FILE *fp = fopen("5.txt", "r");
	char s[10000];
	int i = 0;
	int top = 0;
	while (1) {

		char c = fgetc(fp);
		if (c == -1) break;
		if (c == ';') {
			s[top] = 0;
			//	printf("read:%s\n", s);
			read(s, fun[i++]);
			//printf("%s\n", fun[i - 1].return_name);
			//for (int io1 = 0; io1 < fun[i - 1].len; io1++) {
			//	printf("变量%d:%s\n", io1 + 1, fun[i - 1].name[io1]);
			//}
			top = 0;
		}
		else {
			if (isSpace(c)) c = ' ';
			if (top - 1 >= 0 && isSpace(s[top - 1]) && c == ' ');
			else s[top++] = c;
		}

	}
	fclose(fp);
	return i;
}
Fun *getFunByName(char *name,int count) {
	for (int i = 0; i < count; i++) {
		if (strcmp(fun[i].return_name, name) == 0) {
			return &fun[i];
		}
	}
	return NULL;
}