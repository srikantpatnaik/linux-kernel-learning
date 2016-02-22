/*******************************************************************
* filename: pointers.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 22-02-2016
* last modified: 22-02-2016
* description: arrays and pointers
*******************************************************************/

#include<stdio.h>

int reverse(int b[])
{   int i;
	for(i=4;i>=0;i--){
		b[4-i]=b[i];
	}
}

int main()
{

int a[5] = {10, 20, 30, 40, 50};
printf("sizeof array a: %d\n", sizeof(a)); 

// arrays are internally treated as pointers
printf("Accessing the array with pointer: %d, %d\n", *(a), *(a+1));

reverse(a);
// passing array to function will actually pass pointer to array, hence operation on array
// will affect all copies of that array
printf("Accessing the array with pointer after reverse operation in other function: %d, %d\n", *(a), *(a+1));
}

