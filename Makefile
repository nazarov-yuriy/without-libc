###
# Author: Yuriy Nazarov
###
all:
	nasm -f elf64 stdlib.s -o stdlib.o
	nasm -f elf64 stdio.s  -o stdio.o
	gcc -std=c99 -nostdlib -fno-builtin -c printf.c
	gcc -std=c99 -nostdlib -fno-builtin -c test.c
	ld stdlib.o stdio.o test.o printf.o -o test

clean:
	rm test *.o