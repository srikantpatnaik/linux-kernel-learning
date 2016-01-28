Pointers
--------

#. Pointer size depends on system's address bus size. For a 64 bit
   machine, pointer occupies 8 bytes.

#. Pointers are regular variables, they just meant to store address. 
   Its also possible to retrieve data from the stored address. 

#. An integer pointer is capable of holding address of integer, although
   as mentioned, all pointers can hold 8 byte address, but it is required
   to specify datatype to fetch correct length of data from the stored address.

#. Example, `pointers.c <.src/pointers.c>`_

	.. code-block:: c

		#include<stdio.h>

		int main()
		{
			// Declare pointer. The "*" denotes pointer, and can hold 8 byte address of a char
			char *a, w=5;
			const short *b, x; //with const keyword the value of b cannot be modified
			int *c, y=1000;
			long double *d, z;
			printf("Pointer size: %ld, %ld, %ld, %ld", sizeof(a), sizeof(b), sizeof(c), sizeof(d));
			printf("\nDatatype size: %ld, %ld, %ld, %ld", sizeof(w), sizeof(x), sizeof(y), sizeof(z));
			a = &w;
			// Format specifier for pointer is %p
			// Pointer 'a' contains address of 'w', printing address & value at that address
			printf("\n%p %d", a, *a);
			a++;
			// The address is incremented by 1, as it is char type, for int it will increment by 4
			printf("\nAddress incremented by 1 %p %d", a, *a);
			// Printing a pointer without assigning address will throw a segmentation fault
			// printf("%d", *c); // Uncomment to get segmentation fault
			// Now assign address of 'y' to c
			c = &y;
			*c = 999; // Now one may change the value too
			printf("\nValue stored at c is %d", *c); 
			// Pointer not initialized is a "wild pointer", one must avoid as it can corrupt 
			// random memory location, it is advised to use NULL pointer instead, at least it 
			// will point to base address of the segment
			b = &x;
			//*b = 22; // Uncomment to get the read-only error as b is const type
			printf("\nAddress held by b is %d", *b) ;
			// Dangling pointer will treated later, mostly after malloc()
			return 0;
		}


