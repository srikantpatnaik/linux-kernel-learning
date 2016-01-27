Preprocessor
------------

#. ``C`` compilation steps:

	(Source file) -> Preprocessor -> Compiler -> Assembler -> Linker -> (Executable)

#. Preprocessor do the following:

	#. Macro substitution
	#. Including header file contents (even ``.c`` files)
	#. Conditional compilation

#. All preprocessor instructions always start with ``#`` in source code.

#. Preprocessor generally has syntax ``#define CNAME value|(expression)``.
   CNAME is the name of the constant, must not start with a digit. The 2nd field
   could be a constant value(eg; 10) or an expression(eg; ternary operator).

#. Macros(kind of Unix aliases) are of two types:

	i. Object like macros, examples ::

		#define PI 3.14


		#define myloop for(i=0;i<5;i++) {\
		                 printf("%d ", i);}


	#. Function like macros ::

		#define ADD(x,y) add(x,y)

		#define BIG(x,y)  (x>y) ? x : y

#. The macros can be nested, example ::

		printf("Bigger number: %d\n, BIG(BIG(x,y), z));

#. To view preprocessor output, gcc should be invoked with ``-E`` option. Example ::

	gcc -E test.c -o test.i

#. All relevant function declarations from multiple source files shall be declared
   in a ``.h`` file. Each ``c`` file shall include the local header file. This will
   ensure the use of correct number of arguments with function invocation.

#. ``gcc`` will show the default search path for headers/libraries with ``-v`` flag ::

		gcc -v variadic.c -o /tmp/a.out

#. Conditional compilation allows portion of ``c`` code to compile or ignore. It has
   3 parts

	#. if part: ``if, ifdef, ifndef``
	#. else part(optional): ``else, elif``
	#. end part: ``endif``

#. Example `conditional_compilation.c <./src/conditional_compilation.c>`_

	.. code-block:: c

		#include <stdio.h>

		#define T20 120
		#define INNING 300
		#define SCORE(s) #s //This will replace the string with double quotes(stringification operator)
		#define TOTAL_BALLS(...) printf(__VA_ARGS__) // Variadic macros, this can take any number of args

		int main()
		{
			//If ONEDAY is not defined then define it now
			#ifndef ONEDAY
				#define ONEDAY INNING+INNING
					#ifdef ONEDAY
						printf("One day cricket match has %d balls, ideally one may score %s\n",
								 ONEDAY, SCORE(3600 runs.));
						TOTAL_BALLS("Total balls in T20(%d) and one day(%d) format is %d.",
								 T20, ONEDAY, ONEDAY+T20);
					#else
						printf("An inning usually has %d balls", INNING);
					#endif
			#endif
		}

	Catch the preprocessor action ``gcc -E`` option.

