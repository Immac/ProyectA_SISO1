#include "screenutils.h"

extern void hang(void);

void main() {
  char chr = 'a';
  printChar(chr);
  printChar(chr);
  printChar(chr);
  printChar(chr);
  clearScreen();
  printChar(chr);
  hang();
}

void hang(void) {
    while(1);
}
