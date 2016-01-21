/*******************************************************************
* filename: bitwise.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 21-01-2016
* last modified: 21-01-2016
* description: example bitwise operation
*******************************************************************/

#include<stdio.h>

int main()
{
	// unsigned int/short won't work inside for while decrementing(can't be -ve)
	int a = 10, b, i; // 4 bytes
	// LSB accessed and printed first on screen and so on
	for(i=31;i>=0;i--) {
			b=(a>>i) & 1;
	    	printf("%d",b);
			}
	return 0;
}

