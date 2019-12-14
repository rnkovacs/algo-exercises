/* Given a non-negative integer num, for every number i in 0 <= i <= num
 * calculate the number of 1's in their binary representation and return them
 * as an array.
 *
 * Runtime: 52 ms, faster than 94.39% of C++ online submissions.
 * Memory usage: 9.5 MB, less than 95.12% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::vector<int> countBits(int num) {
  std::vector<int> v (num + 1, 0);
  for (int i=0; i<=num; ++i)
    v[i] = (i & 1) + v[i/2];
  return v;
}

int main() {
  std::cout << "# of bits in numbers up to 5:\n";
  for (int i : countBits(5))
    std::cout << i << ' ';
  std::cout << '\n';
}
