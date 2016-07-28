Functions
---------

#. Variables fall under four storage classes: ``Automatic, Register, Static, External or Global``

#. Variables defined inside a ``{ }`` have the ``block scope``, which means variable get destroyed
   when control moves out of the scope.

#. Comparison

		  +------------------------------------+--------------------+---------+-------------------+-----------------------+-----------------+
		  | Storage class                      | Default value      | Scope   | Lifetime          | Invocation            | Comment         |
		  +====================================+====================+=========+===================+=======================+=================+
		  | Automatic                          | garbage(stack)     | block   | within block      | int a;                |                 |
		  +------------------------------------+--------------------+---------+-------------------+-----------------------+-----------------+
		  | Register(requesting CPU registers) | garbage(CPU/stack) | block   | within block      | register int a = 10;  | NO '&' operator |
		  +------------------------------------+--------------------+---------+-------------------+-----------------------+-----------------+
		  | Static local                       | zero(data or BSS)  | block   | till program ends | static int a = 10;    | see next table  |
		  +------------------------------------+--------------------+---------+-------------------+-----------------------+-----------------+
		  | External or Global                 | zero(data or BSS)  | program | till program ends | declare outside block | see next table  |
		  +------------------------------------+--------------------+---------+-------------------+-----------------------+-----------------+


#. The ``Process address space`` is memory used by an executable on RAM. It can be divided into 5 logical segments.

		  +---------+--------------------------------------------------------+
		  | Segment | Description                                            |
		  +=========+========================================================+
		  | Code    | Stores instructions for the program                    |
		  +---------+--------------------------------------------------------+
		  | Data    | Global & local static variables declared & initialized |
		  +---------+--------------------------------------------------------+
		  | BSS     | Global & local static variables declared               |
		  +---------+--------------------------------------------------------+
		  | Heap    | Holds dynamic memory                                   |
		  +---------+--------------------------------------------------------+
		  | Stack   | Uninitialized local variables                          |
		  +---------+--------------------------------------------------------+

#. Symbols in global scope(functions, variables etc) by default have external linkage.
   Which means a function ``add()`` defined in ``add.c`` file can be used in ``main.c``
   provided they are compiled together ``gcc add.c main.c``. The function ``add()`` need
   not to be declared again in ``main.c``.
   Whereas, in case of variables, check the next example.

#. Say a variable ``int x`` is declared in ``add.c``. As all symbols in global scope
   have external linkage, hence it can be accessed by any other file.
   To use the symbol in other file, one must declare it again as ``extern int x``.

#. A function declaration is desired to stop program to pass arbitrary number of arguments. One may
   create a local header file and include the function declarations to avoid repetitions.

#. Although, it is not required to declare the function in calling file, but adding it
   helps programmer to identify the scope of the function. Example, ``extern int add(int, int)`` in
   ``main.c``.

#. The ``static`` keyword when added to symbols, allow them to link internal only(can't be called
   from other files in the project).

#. The ``variadic function`` can accept variable number of arguments, example, ``printf()``.

#. ``stdarg.h`` declares a type, ``va_list`` for handling variadic functions. ``va_list`` defines
   four macros, ``va_start``, ``va_arg``, ``va_copy``, and ``va_end``.
   Example, `variadic.c <.src/variadic.c>`_

	.. code-block:: c

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


