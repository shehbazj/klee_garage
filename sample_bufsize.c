#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#include <klee/klee.h>
int len;

void allocate(char *buf)
{
	char newbuf[5];
	int i;
	klee_make_symbolic(&len, sizeof(int), "length");
	buf = (char *)malloc(len *sizeof(char));
	for (i = 0 ; i < len ; i++)
		buf[i] = 'a';
	strcpy(newbuf, buf);
	if (len  < 3){
		printf("less than 3\n");
	}else{
		printf("DEADXX\n");
	}
}

int main(int argc, char *argv[])
{
	char * buf;
	allocate(buf);
}
