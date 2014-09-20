/*
 * Author: Yuriy Nazarov
 */

#include "stdarg.h"
#include "stdint.h"
#include "stdio.h"

void print_u64(uint64_t val) {
	char str[20] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
			' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0' };
	int i;
	for (i = 19; i >= 0; i--) {
		str[i] = '0' + val % 10;
		val /= 10;
		if (!val)
			break;
	}
	puts(str + i);
}

void printf(char *fmt, ...) {
	char buff[2] = {0,0};
	va_list va;
	char ch;
	va_start(va, fmt);
	while ((ch = *(fmt++))) {
		if (ch == '%' && fmt[0] != 0) {
			switch (fmt[0]) {
			case 'u':
				print_u64(va_arg(va, unsigned long int));
				break;
			case 's':
				puts(va_arg(va, char*));
				break;
			default:
				break;
			}
			fmt++;
		} else {
			buff[0] = ch;
			puts(buff);
		}
	}
	va_end(va);
}
