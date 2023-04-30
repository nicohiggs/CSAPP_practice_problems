#include <stdio.h>
// the issue is that C has undefined behaviour when shifting by more than the width of the
// data you are trying to shift on. We can fix this by doing multiple smaller shifts

int int_size_is_32() {
  int set_msb = 1 << 31;
  int beyond_msb = 1 << 31 << 1;
  return set_msb && !beyond_msb;
}

int int_size_is_32_16bit() {
  int set_msb = 1 << 15 << 15 << 1;
  int beyond_msb = 1 << 15 << 15 << 2;
  return set_msb && !beyond_msb;
}

int main() {
  printf("%d", int_size_is_32());
  printf("%d", int_size_is_32_16bit());
}
