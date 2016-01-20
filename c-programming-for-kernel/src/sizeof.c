// sizeof.c 
// Demo of compile time and run time instructions 
		
#include<stdio.h>

int main()
{
	int a=1;
	// sizeof() is a compile time operator, whereas ++ is a runtime operator
	sizeof(a++);
	printf("a=%d\n",a);
	return 0;
}

