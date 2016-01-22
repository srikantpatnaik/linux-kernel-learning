/*******************************************************************
* filename: bitwise_multiplication_division.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 22-01-2016
* last modified: 22-01-2016
* description: A faster and preferred way of multiplication/division
********************************************************************/

#include<stdio.h>

int main()
{
	int a=40, b;

	b = a<<1;
	printf("Shifting variable 'a' left by 1 results in multiplication by 2(2^1): a(%d) x 2 = %d", a, b);
	b = a<<3;
	printf("\nShifting variable 'a' left by 3 results in multiplication by 8(2^3): a(%d) x 8 = %d", a, b);
	b = a>>1;
	printf("\nShifting variable 'a' right by 1 results in division by 2(2^1): a(%d) / 2 = %d", a, b);
	b = a>>3;
	printf("\nShifting variable 'a' right by 3 results in division by 8(2^3): a(%d) / 8 = %d", a, b);

	return 0;
}

