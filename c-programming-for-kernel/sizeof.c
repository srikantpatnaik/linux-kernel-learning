#include<stdio.h>

int main()
{
	int a = 10;
	sizeof(a++);
	printf("a=%d\n",a);
	return 0;
}
