#include "screenutils.h"

void clearScreen(void) {
	int i;
	for (i = 0 ; i < ROWS * COLS ; i++ ) {
		printChar(BKSP);
		printChar(CLR);
		printChar(BKSP);
	}
}

void printString(char *str) {
	int i = 0;
	while(str[i] != '\0') {
		printChar(str[i]);
		i++;
	}
}

void readString(char line[ROWS]) {
	char chr;
	int i;
	char end_flag = 0;
	for( i = 0; i < ROWS - 1 ;)
	{
		chr = readChar();
		switch(chr){
			case BKSP:
				printChar(BKSP);
				printChar(CLR);
				i--;
				i = max(0,i);
				break;
			case RTRN:
				end_flag = 1;
				break;
			default:
				line[i] = chr;
				i++;
		}
		printChar(chr);
		line[i] = '\0';
		if(end_flag)
			break;
	}
}

int min(int x , int y) {
	return x < y ? x : y;
}

int max(int x , int y) {
	return x > y ? x : y;
}