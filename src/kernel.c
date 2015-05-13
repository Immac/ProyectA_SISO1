#include "screenutils.h"


extern void hang(void);


void main() {
	char *str = "So nanoka?~";
	char *enter = "\r\n";
	char buffer[ROWS];

	printString(str);
	printString(enter);
	
	readString(buffer);
	printString(enter);
	printString(buffer);
	
	hang();
}

void hang(void) {
    while(1);
}