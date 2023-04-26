#include <stdio.h>

unsigned any_bit_equals_1(int x) {
  return !!x;
}

unsigned any_bit_equals_0(int x) {
  return any_bit_equals_1(~x);
}

unsigned any_bit_equals_1_lsb(int x) {
  return any_bit_equals_1(x & 0xFF);
}

unsigned any_bit_equals_0_msb(int x) {
  return any_bit_equals_0((x >> ((sizeof(int)-1) << 3)));
}

int main() {
  int all_1 = ~0;
  int all_0 = 0;
  int test_1 = 0x12345678;
  int test_2 = 0xFF0000FF;
  int test_3 = 0x00FFFF00;
  
  printf(" %.2x", any_bit_equals_1(all_1));
  printf(" %.2x", any_bit_equals_1(all_0));
  printf(" %.2x", any_bit_equals_1(test_1));
  printf(" %.2x", any_bit_equals_1(test_2));
  printf(" %.2x", any_bit_equals_1(test_3));
  printf("\r\n");

  printf(" %.2x", any_bit_equals_0(all_1));
  printf(" %.2x", any_bit_equals_0(all_0));
  printf(" %.2x", any_bit_equals_0(test_1));
  printf(" %.2x", any_bit_equals_0(test_2));
  printf(" %.2x", any_bit_equals_0(test_3));
  printf("\r\n");

  printf(" %.2x", any_bit_equals_1_lsb(all_1));
  printf(" %.2x", any_bit_equals_1_lsb(all_0));
  printf(" %.2x", any_bit_equals_1_lsb(test_1));
  printf(" %.2x", any_bit_equals_1_lsb(test_2));
  printf(" %.2x", any_bit_equals_1_lsb(test_3));
  printf("\r\n");

  printf(" %.2x", any_bit_equals_0_msb(all_1));
  printf(" %.2x", any_bit_equals_0_msb(all_0));
  printf(" %.2x", any_bit_equals_0_msb(test_1));
  printf(" %.2x", any_bit_equals_0_msb(test_2));
  printf(" %.2x", any_bit_equals_0_msb(test_3));
  printf("\r\n");

  return 0;
}
