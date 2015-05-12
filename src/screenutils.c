#include "screenutils.h"
void clearScreen(void) {
	int i;
	char bksp = '\b';
	char clr = ' ';
	for (i = 0 ; i < ROWS * COLS ; i++ ) {
		printChar(bksp);
		printChar(clr);
		printChar(bksp);
	}
}