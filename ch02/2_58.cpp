#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian() {
  int x = 1;
  byte_pointer start;
  start = (byte_pointer) &x;
  size_t len = sizeof(int);

  if (start[0] == x) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  is_little_endian();
}

