Operators
---------

#. Operators can be broadly classified into ``unary`` (++,--,!, etc) and ``binary`` (||,
   &&,>,>> etc).

#. Logical ``AND(&&)`` and ``OR(||)`` operators must be dealt with care. If the
   first operand returns True in case of ``OR`` compiler does not evaluate
   second, similarly in ``AND``, if first operand returns False then second is
   ignored.

#. Conditional operator(a.k.a ternary operator) requires three mandatory
   operands. Think it as a if/else conditional. Example, `conditional.c <./src/conditional.c>`_

	.. code-block:: c

		#include<stdio.h>

		int main()
		{
			int a = 15;
			int b = 10;
			(a>b) ? printf("a(%d) is greater than b(%d)",a,b) : printf("'a' is smaller than 'b'");
			return 0;
		}

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

#. This is next
