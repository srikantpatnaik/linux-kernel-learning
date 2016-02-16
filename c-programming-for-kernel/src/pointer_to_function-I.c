/*******************************************************************
* filename: pointer_to_function.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 16-02-2016
* last modified: 16-02-2016
* description: Pointer pointing to function - I
*******************************************************************/

#include<stdio.h>

int add(int a, int b)
{
	printf("I'm in add function\n");
	return(a+b);
}

int main()
{
	int x;
	// declare pointer to a function. 'int' is returned and accepts int arguments
	int (*p)(int, int) = &add;
	// invokes the function (unlike datatypes which fetch the value, ofcourse)
	x = (*p)(10, 5);
	printf("Sum returned from add function is %d", x);

}

