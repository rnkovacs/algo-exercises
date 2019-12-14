/* Runtime: 4 ms, faster than 67.09% of C++ online submissions.
 * Memory usage: 8.3 MB, less than 39.02% of C++ online submissions.
 */

#include <iostream>

int hammingWeight(uint32_t n) {
  int num = 0;
  for (int i=0; i<32; ++i)
    num += (n & (1 << i)) >> i;
  return num;
}

int main() {
  std::cout << "# of 1s in 19 : " << hammingWeight(19) << '\n';
}
