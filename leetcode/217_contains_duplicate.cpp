/* Given an array of integers, find if the array contains any duplicates.
 *
 * Runtime: 28 ms, faster than 96.79% of C++ online submissions.
 * Memory usage: 11.3 MB, less than 95.60% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool containsDuplicate(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end());
  for (int i=1, size=nums.size(); i<size; ++i) {
      if (nums[i] == nums[i-1]) return true;
  }
  return false;
}

int main() {
  std::vector<int> v {1,2,3,1};
  std::cout << containsDuplicate(v) << '\n';
}
