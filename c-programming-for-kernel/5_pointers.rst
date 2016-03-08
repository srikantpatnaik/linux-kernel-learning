Pointers
--------

#. Pointer size depends on system's address bus size. For a 64 bit
   machine, pointer occupies 8 bytes.

#. Pointers are regular variables, they just meant to store address. 
   Its also possible to retrieve data from the stored address. 

#. An integer pointer is capable of holding address of integer, although
   as mentioned, all pointers can hold 8 byte address, but it is required
   to specify datatype to fetch correct length of data from the stored address.

#. Example, `pointers.c <./src/pointers.c>`_

	.. code-block:: c

		#include<stdio.h>

		int main()
		{
			// Declare pointer. The "*" denotes pointer, and can hold 8 byte address of a char
			char *a, w=5;
			const short *b, x; // With const keyword the value of b cannot be modified
			int *c, y=1000;
			long double *d, z;

			void *p ; // Can store address of any datatype also called *generic pointer*
			// Storing address of char variable 
			p = &w; 
			// Changing void pointer character pointer by type casting
			*(char *)p = 10; // Modifying w with 10
			printf("Void pointer type casted to hold 'char' address and modified w to %d", *(char *)p);
			// Similarly void pointer can be type casted to any other datatype

			printf("\nPointer size: %ld, %ld, %ld, %ld", sizeof(a), sizeof(b), sizeof(c), sizeof(d));
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
			printf("\nAddress held by b is %d", *b);
			// Dangling pointer will treated later, mostly after malloc()
			return 0;
			/* This example section might grow*/
		
		}

#. Example on how to declare and call function through pointers, `pointer_to_function-I.c <./src/pointer_to_function-I.c>`_

	.. code-block:: c

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
			/*Looks complex? Check the next*/
		}

#. Example, pointer to a function returning integer pointer, `pointer_to_function-II.c <./src/pointer_to_function-II.c>`_

	.. code-block:: c

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
			/* There are even more, check out yourself*/
		}

#. The arrays are internally referenced as pointers. For eg;
   The compiler reserves 20 bytes(4 bytes x 5) for ``int a[5]``.

#. Array passed as function argument doesn't reserves any extra bytes, despite, compiler
   internally points to original array. Hence any modification in array in passing function
   will reflect in original array. Example, `pointer_to_array.c <./src/pointer_to_array.c>`_

	.. code-block:: c

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
		/*explore more*/
		
		}

#.  Example, 2D array and accessing them using pointers `2d_array.c <./src/2d_array.c>`_ 

	.. code-block:: c

		#include<stdio.h>

		int main()
		{

		int i, j;

		// 3 rows 2 columns
		int a[3][2] = {{10, 20}, \
					   {30, 40}, \
					   {50, 60}};
		printf("sizeof array a: %d\n", sizeof(a)); 

		for(i=0;i<3;i++) {
			for(j=0;j<2;j++) {
				// uncomment next line to access elements using indexing
				//printf("%d, ", a[i][j]); 
				// accessing array elements using pointers(same result)
				printf("2D array using pointers: %d ([%d %d] %p), ", *(*(a+i)+j), i, j, &(*(*(a+i)+j)));
			}
			printf("\n");
			/*explore more*/
		}
		}

#. 
