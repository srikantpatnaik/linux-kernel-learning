/*******************************************************************
* filename: conditionals.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 21-01-2016
* last modified: 21-01-2016
* description: example with conditional(ternary)(?:) operator
*******************************************************************/

#include<stdio.h>

int main()
{
	int a = 15;
	int b = 10;
	(a>b) ? printf("a(%d) is greater than b(%d)",a,b) : printf("'a' is smaller than 'b'");
	return 0;
}

