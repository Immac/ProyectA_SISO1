#ifndef SCREEN_UTILS
#define SCREEN_UTILS

#define ROWS 80
#define COLS 25
#define BKSP 0x08
#define RTRN 0x0D
#define CLR 0x20

extern void printChar(chr);
char chr; //Assembly function

extern void clearScreen(void);

extern void printString(str);
char *str;

extern void readString(line);
char line[ROWS];

extern char readChar(void);

extern int min( x , y);
int x; int y;

extern int max( x , y);
int x; int y;
#endif //SCREEN_UTILS