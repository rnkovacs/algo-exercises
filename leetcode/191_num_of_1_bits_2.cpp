/* Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.1 MB, less than 92.68% of C++ online submissions.
 */

#include <iostream>

int hammingWeight(uint32_t n) {
  int num = 0;
  while (n > 0) {
    num += n & 1;
    n >>= 1;
  }
  return num;
}

int main() {
  std::cout << "# of 1s in 19 : " << hammingWeight(19) << '\n';
}
