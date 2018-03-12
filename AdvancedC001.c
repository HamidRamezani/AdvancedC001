/*
 ============================================================================
 Name        : AdvancedC001.c
 Author      : Hamid Ramezani
 Version     :
 Copyright   : All rights are reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char c;
	int  i;
	short s;
	double d;
	long l;
	long long ll;
	long double	ld;
} myStruct;

int main(void) {

	/* check the system data type size -----------------------------------------------------*/
	printf("size of char        is %02d bytes.\n",(int)sizeof(char));
	printf("size of short       is %02d bytes.\n",(int)sizeof(short));
	printf("size of int         is %02d bytes.\n",(int)sizeof(int));
	printf("size of long        is %02d bytes.\n",(int)sizeof(long));
	printf("size of long long   is %02d bytes.\n",(int)sizeof(long long));
	printf("size of float       is %02d bytes.\n",(int)sizeof(float));
	printf("size of double      is %02d bytes.\n",(int)sizeof(double));
	printf("size of long double is %02d bytes.\n",(int)sizeof(long double));
	printf("size of myStruct    is %02d bytes.\n",(int)sizeof(myStruct));
	/*--------------------------------------------------------------------------------------*/

	/* check the system pointer size -------------------------------------------------------*/
	printf("\n");
	printf("size of void*     is %d bytes.\n",(int)sizeof(void*));
	printf("size of char*     is %d bytes.\n",(int)sizeof(char*));
	printf("size of short*    is %d bytes.\n",(int)sizeof(short*));
	printf("size of int*      is %d bytes.\n",(int)sizeof(int*));
	printf("size of long*     is %d bytes.\n",(int)sizeof(long*));
	printf("size of float*    is %d bytes.\n",(int)sizeof(float*));
	printf("size of double*   is %d bytes.\n",(int)sizeof(double*));
	printf("size of myStruct* is %d bytes.\n",(int)sizeof(myStruct*));
	/*--------------------------------------------------------------------------------------*/

	/* let's do some type casting ----------------------------------------------------------*/
	int       N = 3;
	int      *i = (int*     )malloc(N*sizeof(int   ));   /* creat memory for 10 integers */
	double   *d = (double*  )malloc(N*sizeof(double));   /* creat memory for 10 double   */
	myStruct *s = (myStruct*)malloc(N*sizeof(myStruct)); /* creat memory for 10 structs  */

	for(int n = 0; n < N;n++){
		*(i+n)    =  n+1;
		*(d+n)    = (n+1) / 10.0;
		 (s+n)->i = n+1;
	}
	printf("\n");
	printf("address of *i is %p\n",i);
	printf("address of *d is %p\n",d);
	printf("address of *s is %p\n",s);
	/*--------------------------------------------------------------------------------------*/


	/*lets define a 64 bit integer to pass some pointes -----------------------------------*/
	printf("\n");
	void* p = NULL;


	p = i;
	printf("\n");
	for(int n = 0 ; n < N; n++){
		printf("*(p+%d) = %d \n",n,*((int*)p+n));
	}

	printf("\n");
	p = d;
	for(int n = 0 ; n < N; n++){
		printf("*(p+%d) = %f \n",n,*((double*)p+n));
	}

	printf("\n");
	p = s;
	for(int n = 0 ; n < N; n++){
		printf(" (p+%d)->i = %d \n",n,((myStruct*)p+n)->i);
	}
	/*--------------------------------------------------------------------------------------*/

	/* lets define an array of pointers using generic pointer -------------------------------*/
	void** pp = (void**)malloc(3*sizeof(void*));
	pp[0] = i;
	pp[1] = d;
	pp[2] = s;
	printf("\n");
	for(int n = 0 ; n < 3; n++){
		printf("address of pp[%d] is %p\n",n,pp[n]);
	}
	/*--------------------------------------------------------------------------------------*/
	printf("\n");
	for(int n = 0 ; n < N; n++){
		printf("*(pp[1]+%d) = %f \n",n,*((double*)pp[1]+n));
	}
	/* print values of the integer pointer -------------------------------------------------*/

	free(i);
	free(d);
	free(s);
	puts("Done ..."); /* prints Done ... */
	return EXIT_SUCCESS;
}
