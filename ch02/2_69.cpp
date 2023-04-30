#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
  int top_n_bits = x >> ((sizeof(int) << 3) - n);
  x = x << n;
  return x | top_n_bits;
}

int main() {
  printf("%.x\n", rotate_left(0x12345678, 4));
  printf("%.x\n", rotate_left(0x12345678, 20));
}
