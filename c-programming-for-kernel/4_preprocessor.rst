Preprocessor
------------

#. ``C`` compilation steps:

	(Source file) -> Preprocessor -> Compiler -> Assembler -> Linker -> (Executable)

#. Preprocessor do the following:

	#. Macro substitution
	#. Including header file contents
	#. Conditional compilation

#. All preprocessor instructions always start with ``#`` in source code.

#. Macros(kind of Unix aliases) are of two types:

	i. Object like macros, examples ::

		#define PI 3.14


		#define myloop for(i=0;i<5;i++) {        \
							printf("%d ", i);    \
						} 						 \


	#. Function like macros ::

		test
