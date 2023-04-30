#include <stdio.h>

int fits_bits(int x, int n) {
  int w = sizeof(int) << 3;
  return (x << (w-n) >> (w-n)) == x;
}

int main() {
  printf("%d\n", fits_bits(0x000000FF, 31));
  printf("%d\n", fits_bits(0x000000FF, 9));
  printf("%d\n", fits_bits(0x000000FF, 7));
  printf("%d\n", fits_bits(0x00FF0000, 9));

  return 0;
}
