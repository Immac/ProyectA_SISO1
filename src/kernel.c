
#define MAX_BIT_VALUE 0xF
#define WHITE 7
#define BLACK 0

#include "directprint.h"

extern void loop(void);
extern void printChar(char chr);

void main() {
  int x = 0;
  int y = 0;
  int color = 0;
  int i = 0;
  char *my_string = "Hello, Za Warudo!";
  
  clearScreen();
  for(i = 0; i < MAX_BIT_VALUE; i++){
      printStringDirect(my_string,i,x,y);
      y++;
  }
  loop();
}



void loop(void) {
    while(1);
}


