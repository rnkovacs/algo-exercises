/* Given an integer, write a function to determine if it is a power of three.
 *
 * Runtime: 8 ms, faster than 95.63% of C++ online submissions.
 * Memory usage: 7.4 MB, less than 100.00% of C++ online submissions.
 */

#include <cmath>
#include <iostream>

bool isPowerOfThree(int n) {
  return n > 0 && (int) std::pow(3, 19) % n == 0;
}

int main() {
  std::cout << "27 is power of 3: " << isPowerOfThree(27) << '\n';
  std::cout << "0 is power of 3: " << isPowerOfThree(0) << '\n';
}
