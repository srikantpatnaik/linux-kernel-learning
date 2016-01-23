/*******************************************************************
* filename: bitwise_onoff.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 23-01-2016
* last modified: 23-01-2016
* description: toggling a bit
*******************************************************************/

#include <stdio.h>

printbits(short int x)
{
	int i;
	for(i=15; i>=0; i--) {
		printf("%d", x>>i & 0x1);
		if (!(i % 4)) {
			printf(" "); // insert space after 4 characters
		}
	}
	printf("\n");
}

int main()
{
	short int a = 255, b = 1; // 2 byte variable
	// a = 255 (0000 0000 1111 1111)
	printbits(a);
	// Turn ON 13th bit (from right to left)
	// It should look like this (0001 0000 1111 1111)
	printbits(a | (b << 12));
	// Similarly, for OFF, perform bitwise AND operation
	return 0;
}

