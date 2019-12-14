/* Given a non-negative integer num, for every number i in 0 <= i <= num
 * calculate the number of 1's in their binary representation and return them
 * as an array.
 *
 * Runtime: 52 ms, faster than 94.39% of C++ online submissions.
 * Memory usage: 9.9 MB, less than 36.59% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::vector<int> countBits(int num) {
  int N = (num < 256) ? (num + 1) : 256;

  int bitNums[N];
  bitNums[0] = 0;
  for (int i=1; i<N; ++i) {
    bitNums[i] = (i & 1) + bitNums[i/2];
  }

  std::vector<int> v;
  int count;
  for (int n=0; n<=num; ++n) {
    unsigned char *p = (unsigned char *) &n;
    count = 0;
    count += bitNums[p[0]];
    count += bitNums[p[1]];
    count += bitNums[p[2]];
    count += bitNums[p[3]];
    v.push_back(count);
  }
  
  return v;
}

int main() {
  std::cout << "# of bits in numbers up to 5:\n";
  for (int i : countBits(5))
    std::cout << i << ' ';
  std::cout << '\n';
}
