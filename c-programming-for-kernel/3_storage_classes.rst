Functions
---------

#. Variables fall under four storage classes: ``Automatic, Static, Register, External or Global``

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

#. A function decleration is desired to stop program to pass arbitrary number of arguments.

#. Although, it is not required to declare the function in calling file, but adding it
   helps programmer to identify the scope of the function. Example, ``extern int add(int, int)`` in
   ``main.c``.

#. The ``static`` keyword when added to symbols, allow them to link internal only(can't be called
   from other files in the project).



