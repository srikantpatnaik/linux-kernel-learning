/*******************************************************************
* filename: bitwise_optimization.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 23-01-2016
* last modified: 23-01-2016
* description: storing multiple integers in one variable
*******************************************************************/

#include <stdio.h>

#define MASK 255 // 0xFF

int main()
{
	short int a = 5, b = 254, c; // 2 byte variable
	// a = 5 (101),  b = 254 (1111 1110)
	// we can store both a,b inside c and save some memory
	c = a << 8; // c = (0000 0101 0000 0000)
	c = c | b;  // c = (0000 0101 1111 1110), No need of shifting
	// At this point we can destroy a, b variable
	// To retrieve value of 'a' from 'c'
	printf("a = %d",c>>8);
	printf("\nb = %d",c & MASK);
	return 0;
}

