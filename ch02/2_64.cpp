#include <stdio.h>

int any_odd_one(unsigned x) {
  // 10101010 is 0xAA
  // using the !! trick to return 1 if any bit is set
  return  !!(x & 0xAAAAAAAA);
}

int main() {
  printf("%.2x\n", any_odd_one(0x000000FF));
  printf("%.2x\n", any_odd_one(0x00001500));
  printf("%.2x\n", any_odd_one(~0));
  printf("%.2x\n", any_odd_one(0));
  return 0;
}
