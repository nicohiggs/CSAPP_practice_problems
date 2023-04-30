#include <stdio.h>

int odd_ones(unsigned x) {
  // using the parity checking idea whereby shifting by powers of 2
  // and then XOR with yourself is the same as comparing the corresponding
  // bits 'beside' each other which then reduces to 00, 10, 01, 11 in which
  // we see XOR is even/odd (00/11 even, 10, 01 odd)
  int parity = x ^ (x >> 1);
  parity = parity ^ (parity >> 2);
  parity = parity ^ (parity >> 4);
  parity = parity ^ (parity >> 8);
  parity = parity ^ (parity >> 16);
  return parity & 0x1;
}

int main() {
  printf("%.2x\n", odd_ones(0x000000FF));
  printf("%.2x\n", odd_ones(0x00000FFF));
  printf("%.2x\n", odd_ones(0x0000FF00));
  printf("%.2x\n", odd_ones(0x00070000));
  printf("%.2x\n", odd_ones(0x00000001));
  printf("%.2x\n", odd_ones(0));
  printf("%.2x\n", odd_ones(~0));
  return 0;
}
