Datatypes
---------




#. ``C`` operators could be ``compile time`` or a ``run time`` instruction. One must be very
   careful while using them together. 
   A *compile time* instruction will assign value at compile time and will not change during
   execution. Whereas, a *run time* instruction gets updated during execution. 
   Example, `sizeof.c <./src/sizeof.c>`_

	.. code-block:: c
		
		// sizeof.c 
		// Demo of compile time and run time instructions 
		
		#include<stdio.h>

		int main()
		{
			int a=1;
			// sizeof() is a compile time operator, whereas ++ is a runtime operator
			sizeof(a++);
			printf("a=%d\n",a);
			return 0;
		
	This prints ``a=1``, which means the runtime unary operator ``++`` inside ``sizeof()`` never 
	gets called. 

#. This is next.
