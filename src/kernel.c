#include "screenutils.h"

extern void hang(void);
extern void readSector(bufferm,sector);
extern void makeInterrupt21(void);
extern void loadProgram(void);
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
	/*
	char buffer[512];
	printString("So nanoka?~\r\n");
	readSector(buffer,30);
	printString(buffer);
	printString("\r\n done");*/
	makeInterrupt21();
	loadProgram();
	hang();
}

void hang(void) {
    while(1);
}