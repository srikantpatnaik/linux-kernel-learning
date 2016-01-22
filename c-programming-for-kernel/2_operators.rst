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

#.
