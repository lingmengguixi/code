#include "pch.h"
#include <iostream>
#include "myhead.h"
extern Fun  fun[211];
int main()
{
	vector<char*> lists=readOkFun();
	int count = init();
	for (int i = 0; i < lists.size(); i++) {
		printf("%02d %s\n",i+1,lists[i]);
	}
	printf("need:%d had:%d\n",lists.size(),count);
	for (int i = 0; i <lists.size(); i++) {
		//printf("%s %s\n", lists[i], getFunByName(lists[i], count) == NULL ? "no find":"ok");
		if (getFunByName(lists[i], count) == NULL) printf("%s\n", lists[i]);
	 }
	system("pause");
}

