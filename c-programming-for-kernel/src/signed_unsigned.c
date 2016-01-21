/*******************************************************************
* filename: signed_unsigned.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 21-01-2016
* last modified: 21-01-2016
* description: conditional operation on different qualifiers
*******************************************************************/

#include<stdio.h>

int main()
{
	unsigned int a = 5;
	signed int b = 100;

	// This shall print the expected output, although mismatch in datatypes
	// Both positive numbers
	if (b>a) {
		printf("b(%d) greater than a(%d)", b,a);
	}

	unsigned int c = 5;
	signed int d = -100;

	// This yield incorrect result as d is negative
	if (c>d) {
		printf("\nc(%d) greater than d(%d)", c,d);
	}

	signed int e = 5;
	signed int f = -100;

	// This works, as both are signed numbers (although f is negative)
	if (e>f) {
		printf("\ne(%d) greater than f(%d)", e,f);
	}
	return 0;
}

