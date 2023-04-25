#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
  return (x & ~(0xFF << i*8)) | (b << i*8);
}

int main() {
  unsigned x = replace_byte(0x12345678, 2, 0xAB);
  printf(" %.2x", x);
  x = replace_byte(0x12345678, 0, 0xAB);
  printf(" %.2x", x);
  return 0;
}
