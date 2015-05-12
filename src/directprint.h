#ifndef PRINT_STRING_DIRECT
#define PRINT_STRING_DIRECT

#define ROWS 80
#define COLS 25
#define DISPLAY_CHAR_SIZE 2
#define VIDEO_ADDRESS_BASE 0x8000
#define VIDEO_ADDRESS_SEGMENT 0xB000

extern void putInMemory(segment,address,character);
int segment; int address; char character;
extern void clearScreenDirect();
extern void printStringDirect(string,color,xCoordinate,yCoordinate);
char *string;int color;int xCoordinate; int yCoordinate;
extern int computePosition(xCoordinate,yCoordinate);
int xCoordinate; int yCoordinate;

#endif //PRINT_STRING_DIRECT