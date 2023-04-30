#include <stdio.h>

int int_shifts_are_arithmetic() {
  int x = ~0;
  return !(x ^ (x >> 1));
}

int main() {
  printf("%d", int_shifts_are_arithmetic());
  return 0;
}
