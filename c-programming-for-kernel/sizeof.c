#include<stdio.h>

int main()
{
	int a = 10,b;
	b=sizeof(a++);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}
