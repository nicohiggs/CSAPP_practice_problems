#include <stdio.h>

unsigned srl(unsigned x, int k) {
  unsigned xrsa = (int) x >> k;
  // idea is to grab top k bits e.g. 11100000, but then we need to
  // & with 00011111 so we lose the top k and keep the rest
  int top_k_bits = ~0 << ((sizeof(int) << 3) - k);
  return xrsa & ~top_k_bits;
}

int sra(int x, int k) {
  int xrsl = (unsigned) x >> k;
  // similar idea of grabbing top k bits, then we determine
  // whether to add ones or not depending on the leading bit,
  // then we use or with either the top bits or nothing
  // e.g. 11100000 or 00000000 depending on leading bit
  int top_k_bits = ~0 << ((sizeof(int) << 3) - k);
  int leading_bit = x & (1 << ((sizeof(int) << 3) - 1));
  // if the leading bit was 1 then !leading_bit is 0 else it's 00...010...0
  // so a -1 results in either all 1's or 0's till first bit and then all 1's
  top_k_bits = top_k_bits & ((!leading_bit) - 1);
  return xrsl | top_k_bits;
}

int main() {
  printf("%.2x\n", srl(~0, 7));
  printf("%.2x\n", sra(~0, 7));
  return 0;
}
