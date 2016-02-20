/*******************************************************************
* filename: pointer_to_function.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 20-02-2016
* last modified: 20-02-2016
* description: Pointer to function: returning integer pointer - II
*******************************************************************/

#include<stdio.h>

// function returning integer pointer, i.e address of variable
int * add(int a, int b)
{   // must use static to retain value across functions
	static int result;
	result = a + b;
	printf("address of result: %p\n", &result);
	// seg fault if return statement not provided
	return &result;
}

int main()
{
	// declare a pointer type to hold address of result from add function
	int *x;
	// declare pointer to a function. 'integer' pointer is returned and accepts integer arguments
	int * (*p)(int, int) = &add;
	// invokes the function and expects integer pointer as return value
	x = (*p)(10, 5);
	printf("Value stored at address held by 'result': %d\n", *x);
	printf("Address stored in 'result' returned from 'add' function: %p", x);

}

