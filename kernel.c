#define ROWS 80
#define COLS 25
#define DISPLAY_CHAR_SIZE 2
#define VIDEO_ADDRESS_B 0x8000
#define VIDEO_ADDRESS_SEGMENT 0xB000
#define WHITE 7

extern void putInMemory (int segment,int address,int character);
extern int computePosition(int xCoordinate, int yCoordinate);
extern void loop(void);
extern void print_string(char *string,int color,int xCoordinate, int yCoordinate);

void main() {
  int x = 0;
  int y = 0;
  int color = 0;
  int position;
  int i = 0;
  char *my_string = "ThE WoRlD";
  /*putInMemory(0xB000,0x8140,'A');
  putInMemory(0xB000, 0x8141, WHITE);*/
  position = computePosition(x,y);
  for(i = 0; i < 8; i++){
      print_string(my_string,i,x,y);
      y++;
  }
  loop();
}

int computePosition(int xCoordinate,int yCoordinate) {
  return (xCoordinate) * (ROWS * yCoordinate) * DISPLAY_CHAR_SIZE;
}

void loop(void) {
    while(1) {
    }
}

void print_string(char *string,int color,int xCoordinate,int yCoordinate){
    int position = computePosition(xCoordinate,yCoordinate);
    int i = 0;    
    while (string[i] != '\0') {
	putinMemory(VIDEO_ADDRESS_SEGMENT,VIDEO_ADDRESS_B + position,string[i]);
	position++;
	putinMemory(VIDEO_ADDRESS_SEGMENT,VIDEO_ADDRESS_B + position,color);
	position++;
	i++;
    }
}