/* Given an array containing n distinct numbers from 0,1,2,...,n, find the one
 * that is missing from the array.
 *
 * Runtime: 24 ms, faster than 82.46% of C++ online submissions.
 * Memory usage: 9.8 MB, less than 88.24% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
  int N = nums.size() + 1;
  int sum = 0;
  for (int i : nums)
    sum += i;
  return (N * (N-1) / 2) - sum;
}

int main() {
  std::vector<int> list = {3,2,1};
  for (int i : list) std::cout << i << ' '; std::cout << '\n';
  std::cout << "Missing: " << missingNumber(list) << "\n\n";
  
  std::vector<int> list2 = {0};
  for (int i : list2) std::cout << i << ' '; std::cout << '\n';
  std::cout << "Missing: " << missingNumber(list2) << "\n";
}
