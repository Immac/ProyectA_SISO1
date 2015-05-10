#define ROWS 80
#define COLS 25
#define DISPLAY_CHAR_SIZE 2
#define VIDEO_ADDRESS_BASE 0x8000
#define VIDEO_ADDRESS_SEGMENT 0xB000
#define MAX_BIT_VALUE 0xF
#define WHITE 7
#define BLACK 0


extern void putInMemory (int segment,int address,int character);
extern int computePosition(int xCoordinate, int yCoordinate);
extern void loop(void);
extern void printString(char *string,int color,int xCoordinate, int yCoordinate);
extern void clearScreen(void);

void main() {
  int x = 0;
  int y = 0;
  int color = 0;
  int position;
  int i = 0;
  char *my_string = "Hello, Za Warudo!";
  
  clearScreen();
  position = computePosition(x,y);
  for(i = 0; i < MAX_BIT_VALUE; i++){
      printString(my_string,i,x,y);
      y++;
  }
  loop();
}

int computePosition(int xCoordinate,int yCoordinate) {
  return ((xCoordinate) + (ROWS * yCoordinate)) * DISPLAY_CHAR_SIZE;
}

void loop(void) {
    while(1);
}

void printString(char *string,int color,int xCoordinate,int yCoordinate){
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
	    printString(empty,0,i,j);
	}
    }
}
