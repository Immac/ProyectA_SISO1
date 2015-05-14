#include "screenutils.h"


extern void hang(void);
extern void readSector(bufferm,sector);
char *buffer; int sector;

void main() {
	/*
	char *str = "So nanoka?~";
	char *enter = "\r\n";
	char buffer[ROWS];

	printString(str);
	printString(enter);
	
	readString(buffer);
	printString(enter);
	printString(buffer);
	*/
	char buffer[512];
	printString("started");
	readSector(buffer,30);
	printString(buffer);
	printString("done");
	hang();
}

void hang(void) {
    while(1);
}