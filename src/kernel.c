#include "screenutils.h"

extern void hang(void);
extern void printString(char *str);

void main() {
	char *str = "Hello";
	printString(str);
	hang();
}

void hang(void) {
    while(1);
}

void printString(char *str) {
	int i = 0;
	while(str[i] != '\0') {
		printChar(str[i]);
		i++;
	}
}