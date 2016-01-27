/*******************************************************************
* filename: conditional_compilation.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 27-01-2016
* last modified: 27-01-2016
* description: conditional compilation example. Run the preprocessor
               to see the substitution.
			   $ gcc -E conditional_compilation.c -o /tmp/cc.i
*******************************************************************/

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
