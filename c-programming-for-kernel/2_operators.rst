Operators
---------

#. Operators can be broadly classified into ``unary`` (++,--,!, etc) and ``binary`` (||,
   &&,>,>> etc).

#. Logical ``AND(&&)`` and ``OR(||)`` operators must be dealt with care. If the
   first operand returns True in case of ``OR`` compiler does not evaluate
   second, similarly in ``AND``, if first operand returns False then second is
   ignored.

#. Conditional operator(a.k.a ternary operator) requires three mandatory
   operands. Think it as a if/else conditional. Example, `conditional.c <./src/conditionals.c>`_

	.. code-block:: c

		#include<stdio.h>

		int main()
		{
			int a = 15;
			int b = 10;
			(a>b) ? printf("a(%d) is greater than b(%d)",a,b) : printf("'a' is smaller than 'b'");
			return 0;
		}

#. Bitwise operators have high precedence than arithmetic/logical operations.

#. Bitwise operator is most widely used in accessing hardware registers and
   reading/writing data. Rotate and AND operation is common. Example, `bitwise.c <./src/bitwise.c>`_

	.. code-block:: c

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

#. Multiplication with bitwise operation is preferred over asterisk(*). Shifting left by 1 is
   multiplying by 2, shifting left by 2 is multiplying by 4 and so on. The reverse is true with division.
   Example, `bitwise_multiplication_division.c <./src/bitwise_multiplication_division.c>`_

	.. code-block:: c

		#include<stdio.h>

		int main()
		{
			int a=40, b;

			b = a<<1;
			printf("Shifting variable 'a' left by 1 results in multiplication by 2(2^1): a(%d) x 2 = %d", a, b);
			b = a<<3;
			printf("\nShifting variable 'a' left by 3 results in multiplication by 8(2^3): a(%d) x 8 = %d", a, b);
			b = a>>1;
			printf("\nShifting variable 'a' left by 1 results in division by 2(2^1): a(%d) / 2 = %d", a, b);
			b = a>>3;
			printf("\nShifting variable 'a' left by 3 results in division by 8(2^3): a(%d) / 8 = %d", a, b);

			return 0;
		}

#. Bitwise operations can be useful in memory optimizations. Multiple variables can be
   fit into single variable(provided all bits fit). Example, `bitwise_optimization.c <./src/bitwise_optimization.c>`_

	.. code-block:: c

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

#. Controlling a single bit of a variable. Example, `bitwise_onoff.c <./src/bitwise_onoff.c>`_

	.. code-block:: c

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

