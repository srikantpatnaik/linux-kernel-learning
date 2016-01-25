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

#. ``Process address space`` is memory used by an executable on RAM. It can be divided into 5 logical segments.

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


