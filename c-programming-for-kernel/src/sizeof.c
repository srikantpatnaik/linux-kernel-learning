/*******************************************************************
* filename: sizeof.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 20-01-2016
* last modified: 21-01-2016
* description: compile time and runtime operators
*******************************************************************/

#include<stdio.h>

int main()
{
	int a=1;
	// sizeof() is a compile time operator, whereas ++ is a runtime operator
	sizeof(a++);
	printf("a=%d\n",a);
	return 0;
}

