Datatypes
---------

#. ``unsigned`` & ``short`` modifiers cannot be applied on ``float`` &
``double`` datatypes.

#. CPU can perform operations on same type of operands. For example, it gives
   incorrect results when signed & unsigned integers are compared.
   Example, `signed_unsigned.c <./src/signed_unsigned.c>`_

	.. code-block:: c

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

#. In integer(int) variable, the MSB(most significant bit a.k.a signed bit) carries the
   sign(positive(0)/negative(1)) of the variable. Details in ``/usr/include/limits.h``.

#. Use ``unsigned`` qualifiers if you are using only positive numbers. This will increase the
   range as the MSB will now act as data bit instead of ``signed bit``.


#. ``C`` operators could be ``compile time`` or a ``run time`` instruction. One must be very
   careful while using them together.
   A *compile time* instruction will assign value at compile time and will not change during
   execution. Whereas, a *run time* instruction gets updated during execution.
   Example, `sizeof.c <./src/sizeof.c>`_

	.. code-block:: c

		#include<stdio.h>

		int main()
		{
			int a=1;
			// sizeof() is a compile time operator, whereas ++ is a runtime operator
			sizeof(a++);
			printf("a=%d\n",a);
			return 0;
		}

	This prints ``a=1``, which means the runtime unary operator ``++`` inside ``sizeof()`` never
	gets called.

#. This is next.
