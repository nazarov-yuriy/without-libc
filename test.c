/*
 * Author: Yuriy Nazarov
 */

#include "stdint.h"
#include "stdlib.h"
#include "printf.h"

int main(){
	uint64_t answer = 42;
	printf("Answer to the Ultimate Question of Life, The Universe, and Everything is %u\n", answer);
	return 0;
}

void _start() {
	exit(main());
}
