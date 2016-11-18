#include <klee/klee.h>

#define MAXSTR 10

int test(char *str, int offset) {

	if (str[offset] == '\n') {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {

	char str[MAXSTR];
	int offset;

	klee_make_symbolic(str, MAXSTR, "str");
	offset = klee_int("offset");
	//  klee_make_symbolic(&offset, sizeof(offset),"offset");
	klee_assume(offset >= 0);
	klee_assume(offset < 10);

	int result = test(str, offset);

	return result;
}
