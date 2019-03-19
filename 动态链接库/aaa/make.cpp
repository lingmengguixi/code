#include "pch.h"
Fun fun[200];
int count1 = 0;
void writeTheArgsWithoutName(FILE *fp, int index) {
	for (int j = 0; j < fun[index].len; j++) {
		if (j != 0) fprintf(fp, ",");
		fprintf(fp, "%s", fun[index].var[j]);
	}
}
void writeTheArgsWithName(FILE *fp, int index) {
	for (int j = 0; j < fun[index].len; j++) {
		if (j != 0) fprintf(fp, ",");
		fprintf(fp, "%s %s", fun[index].var[j],fun[index].name[j]);
	}
}
void writeTheArgsOnlyName(FILE *fp, int index) {
	for (int j = 0; j < fun[index].len; j++) {
		if (j != 0) fprintf(fp, ",");
		fprintf(fp, "%s",fun[index].name[j]);
	}
}
int readFunFromFile(const char *fileName,const char *toFileName)
{
	FILE *fp1 = fopen(fileName, "r");
	FILE *fp2 = fopen(toFileName, "w");
	char s[10000];
	int len = 0;
	while (true) {
		int c = fgetc(fp1);
		if (c == -1) {
			if (len != 0) {
				s[len] = 0;
				fprintf(fp2, "%s", s);
				len = 0;
			}
			break;
		}
		if (c == ' ' || c == '\r' || c == '\t' || c == '\n') {
			if (len != 0) {
				s[len] = 0;
				fprintf(fp2, "%s%c", s, c);
				len = 0;
			}
			else fprintf(fp2, "%c", c);
		}
		else if (c == '(') {
			s[len] = 0;
			fprintf(fp2, "(__stdcall *%s1)(", s);
			len = 0;
		}
		else s[len++] = c;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
int init(const char *fileName) {
	FILE *fp = fopen(fileName, "r");
	char s[10000];
	int i = 0;
	int top = 0;
	while (1) {

		char c = fgetc(fp);
		if (c == -1) break;
		if (c == ';') {
			s[top] = 0;
			//	printf("read:%s\n", s);
			readArgs(s, fun[i++]);
			//printf("%s\n", fun[i - 1].return_name);
			//for (int io1 = 0; io1 < fun[i - 1].len; io1++) {
			//	printf("±äÁ¿%d:%s\n", io1 + 1, fun[i - 1].name[io1]);
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
	count1 = i;
	return i;
}
int isSpace(char c) {
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r') return 1;
	return 0;
}
void readArgs(char *s, Fun &fun) {
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
void writeAsReadAddr(const char *fileName) {
	FILE *fp = fopen(fileName, "w");
	//proc = GetProcAddress(hModule, "AcceptEx");
//AcceptEx1 = (BOOL(__stdcall *)(SOCKET, SOCKET, PVOID, DWORD, DWORD, DWORD, LPDWORD, LPOVERLAPPED))proc;

	for (int i = 0; i < count1; i++) {
		fprintf(fp, "proc = GetProcAddress(hModule, \"%s\");\n",fun[i].return_name);
		fprintf(fp, "%s1 = (%s(__stdcall *)(", fun[i].return_name, fun[i].return_var);
		writeTheArgsWithoutName(fp, i);
		fprintf(fp,"))proc;\n");
	}
	fclose(fp);
}
void writeAsBindVarToFun(const char *fileName) {
	FILE *fp = fopen(fileName, "w");
	for (int i = 0; i < count1; i++) {
		fprintf(fp,"%s PASCAL FAR %s(", fun[i].return_var, fun[i].return_name);
		writeTheArgsWithName(fp,i);
		fprintf(fp, "){\n");
		fprintf(fp, "    return %s1(",fun[i].return_name);
		writeTheArgsOnlyName(fp,i);

		fprintf(fp, ");\n}\n");
	}
	fclose(fp);
}