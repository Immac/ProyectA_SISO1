#include "directprint.h"

void printStringDirect(char *string,int color,int xCoordinate,int yCoordinate){
    int position = computePosition(xCoordinate,yCoordinate);
    int i = 0;    
    while (string[i] != '\0') {
	putInMemory(VIDEO_ADDRESS_SEGMENT,VIDEO_ADDRESS_BASE + position,string[i]);
	position++;
	putInMemory(VIDEO_ADDRESS_SEGMENT,VIDEO_ADDRESS_BASE + position,color);
	position++;
	i++;
    }
}

void clearScreen(void) {
    int i;
    int j;
    char *empty = " ";
    for (i = 0 ; i < ROWS ; i++ ) {
	for (j = 0; j < COLS ; j++ ) {
	    printStringDirect(empty,0,i,j);
	}
    }
}

int computePosition(int xCoordinate,int yCoordinate) {
  return ((xCoordinate) + (ROWS * yCoordinate)) * DISPLAY_CHAR_SIZE;
}