#include <stdio.h>

int leftmost_one(unsigned x) {
  // we get everything after the leading 1 bit to be 1, then we can
  // shift >> 1 add simply add 1 so that 0...00111.. becomes 0...01000...
  // (the plus 1 sets off multiple carries to give use the desired result)
  // we use OR's with shifted powers of 2 so that ones get carried over all
  // the lower bits (sort of a play on the odd/even parity one previous)
  int parity = x | (x >> 1);
  parity = parity | (parity >> 2);
  parity = parity | (parity >> 4);
  parity = parity | (parity >> 8);
  parity = parity | (parity >> 16);
  // 0 is a special case so we use x && 1 to catch this
  return (x && 1) + (parity >> 1);
}

int main() {
  printf("%.2x\n", leftmost_one(0x000000FF));
  printf("%.2x\n", leftmost_one(0x6600));
  printf("%.2x\n", leftmost_one(0x0000FF00));
  printf("%.2x\n", leftmost_one(0));
  return 0;
}
