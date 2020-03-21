/* Given an array containing n distinct numbers from 0,1,2,...,n, find
 * the one that is missing from the array.
 *
 * Runtime: 24 ms, faster than 80.14% of C++ online submissions.
 * Memory usage: 9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <numeric>
#include <vector>

int missingNumber(std::vector<int> &nums) {
  int n = nums.size();
  int sumNPlusOne = n * (n + 1) / 2;
  int sumN = std::accumulate(nums.begin(), nums.end(), 0);
  return sumNPlusOne - sumN;
}

int main() {
  std::vector<int> list = {3,2,1};
  for (int i : list) std::cout << i << ' '; std::cout << '\n';
  std::cout << "Missing: " << missingNumber(list) << "\n\n";
  
  std::vector<int> list2 = {0};
  for (int i : list2) std::cout << i << ' '; std::cout << '\n';
  std::cout << "Missing: " << missingNumber(list2) << "\n";
}
