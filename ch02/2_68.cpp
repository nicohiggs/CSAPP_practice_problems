#include <stdio.h>

int lower_one_mask(int n) {
  int x = ~0;
  x = x << n;
  x = ~x;
  return x;
}

int main() {
  printf("%.2x, %.2x", lower_one_mask(6), lower_one_mask(17));
  return 0;
}
