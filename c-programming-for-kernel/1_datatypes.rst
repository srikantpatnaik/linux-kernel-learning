Datatypes
---------

#. ``C`` instructions can be broadly classified into ``compile time`` &
   ``run time`` instructions. Check the example, `sizeof.c <./sizeof.c>`_ in ``pwd``

	.. code-block:: c

		// Demo of compile time and run time instructions 
		
		#include<stdio.h>

		int main()
		{
			int a=1, b;
			// sizeof() is a compile time instruction. 
			sizeof(a++);
			printf("a=%d\n",a);
			return 0;
		}

#. This is next
