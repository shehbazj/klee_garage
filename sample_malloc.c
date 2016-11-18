#include<stdlib.h>
#include<klee/klee.h>
#include<string.h>
#include<stdio.h>
#include<assert.h>

//#define ARRSIZE 10

void fun(char *a, int arrsize)
{
	if(arrsize < 5){
		printf("Less than 5\n");
	}else if(arrsize <= 10) {
		printf("Less than equal to 10\n");
	}else{
		printf("grter than 10\n");
	}
}


int main(int argc, char *argv[])
{
	char *a;
	int arrsize;
	a = (char *)malloc(sizeof(char)*arrsize);
//	klee_make_symbolic(&arrsize, sizeof(arrsize), "size" );
	arrsize = klee_int("size");
//	klee_make_symbolic();
	klee_assert(arrsize > 1);
	klee_assert(arrsize < 10);
	fun(a,arrsize );
	free(a);
	return 0;
}
