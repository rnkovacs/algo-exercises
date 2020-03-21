/* Reverse bits of a given 32-bit unsigned integer.
 *
 * Runtime: 0 ms, faster than 100% of C++ online submissions.
 * Memory usage: 7.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

uint32_t reverseBits(uint32_t n) {
  uint32_t res = 0;
  for (int i=0; i<32; ++i) {
    res |= (n & 1) << (31 - i);
    n >>= 1;
  }
  return res;
}

int main() {
  uint32_t u = 43261596;
  std::cout << u << '\n' << reverseBits(u) << '\n';
}
