// The problem is the failure with negative numbers
// instead we need to shift the byte we want all the way left so
// that when we shift it all the way back right the arithmetic shift
// will handle negatives for us
#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
  return word << ((3 - bytenum) << 3) >> 24;
}

int main() {
  printf("%.2x\n", xbyte(0x000000FF, 0));
  printf("%.2x\n", xbyte(0x0000FF00, 1));
  printf("%.2x\n", xbyte(0x00FF0000, 2));
  printf("%.2x\n", xbyte(0xFF000000, 3));
  printf("%.2x\n", xbyte(0x00AA00FF, 2));
  printf("%.2x\n", xbyte(0x1BAA00FF, 3));
  return 0;
}
