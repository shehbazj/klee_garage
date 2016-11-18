#include<stdio.h>
#include<klee/klee.h>

int test(int length)
{
	int i;
	int x=0;
	for (i = 0; i < length ; i++){
		x = x+1;		
	}
	return x;
}

int test2(int breadth)
{
	int x = 5;
	if (x < breadth){
	return 4	;
	}else{
	return 6;
}
	return 0;
}

int main(int argc, char * argv[])
{
	int length;
	klee_make_symbolic(&length,sizeof(length), "length" );
//	klee_assume(length > 1);
//	klee_assume(length < 10);
	int x = test(length);
//	int breadth;
//	klee_make_symbolic(&breadth,sizeof(breadth), "breadth" );
//	test2(breadth);
	return 0;
}
