/* Given an array containing n distinct numbers from 0,1,2,...,n, find the one
 * that is missing from the array.
 *
 * Runtime: 140 ms, faster than 5.69% of C++ online submissions.
 * Memory usage: 9.8 MB, less than 98.04% of C++ online submissions.
 */

#include <bitset>
#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
  int N = nums.size() + 1;
  
  std::bitset<10000> b = 0;
  std::bitset<10000> one = 1;

  for (int i : nums)
    b |= (one << i);
  
  b = ~b;
  
  for (int i=0; i<N; ++i) {
    if ((b & one) == one) return i;
    b >>= 1;
  }
  
  std::cerr << "unreachable";
  return -1;
}

int main() {
  std::vector<int> list = {3,2,1};
  for (int i : list) std::cout << i << ' '; std::cout << '\n';
  std::cout << "Missing: " << missingNumber(list) << "\n\n";
  
  std::vector<int> list2 = {0};
  for (int i : list2) std::cout << i << ' '; std::cout << '\n';
  std::cout << "Missing: " << missingNumber(list2) << "\n";
}
