/*******************************************************************
* filename: variadic.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 27-01-2016
* last modified: 27-01-2016
* description: example variadic function: multiplying arguments
*******************************************************************/

#include <stdio.h>
#include <stdarg.h>

// declaring a variadic function. The count variable holds number of
// incoming arguments. Although, such arrangement is not enforced by
// C language or compiler, but it is always easier to iterate if
// count is known.
int products(int count, ...);

int products(int count, ...)
{
	va_list pr;
	int product = 1;
	int i=0;

	// requires last fixed argument for address, in our case the only argument count.
	va_start(pr, count);

	for(; i < count; i++) {
		// va_arg expects va_list, and type of the next variable. On every invocation
		// it returns the value in the next argument.
		product*=va_arg(pr, int);
	}
	// ending/freeing memory is highly recommended
	va_end(pr);

	return product;
}


int main()
{
	// calling variadic function
	printf("The result is %d", products(4, 22, 11, 2, 1));
	return 0;
}

