#include <stdio.h>

int construct_word(int x, int y) {
  return (x & 0xFF) | (y & ~0xFF);
}

int main() {
  int x = 0x89ABCDEF;
  int y = 0x76543210;

  int z = construct_word(x, y);
  printf(" %.2x", z);

  return 0;
}
