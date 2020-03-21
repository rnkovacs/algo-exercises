/* The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

int hammingDistance(int x, int y) {
  int xored = x ^ y;
  int count = 0;
  while (xored > 0) {
    xored &= xored - 1;
    ++count;
  }     
  return count;
}

int main() {
  std::cout << "Hamming distance of 1 and 4: " << hammingDistance(1, 4) << '\n';
}
