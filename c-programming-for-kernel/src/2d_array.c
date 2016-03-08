/*******************************************************************
* filename: 2d_array.c
* author: Srikant Patnaik (srikant@gnu-linux.org)
* license: GNU GPLv3
* first written: 29-02-2016
* last modified: 29-02-2016
* description: double dimensional arrays
*******************************************************************/

#include<stdio.h>

int main()
{

int i, j;

// 3 rows 2 columns
int a[3][2] = {{10, 20}, \
			   {30, 40}, \
			   {50, 60}};
printf("sizeof array a: %d\n", sizeof(a)); 

for(i=0;i<3;i++) {
	for(j=0;j<2;j++) {
		// uncomment next line to access elements using indexing
		//printf("%d, ", a[i][j]); 
		// accessing array elements using pointers(same result)
		printf("2D array using pointers: %d ([%d %d] %p), ", *(*(a+i)+j), i, j, &(*(*(a+i)+j)));
	}
	printf("\n");
}
}
