/* Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 *
 * Runtime: 12 ms, faster than 96.47% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> &nums) {
  int N = nums.size();
  int curr = 0;
  // 0 1 0 3 12
  // 1 3 12 
  for (int i = 0; i < N; ++i) {
    if (nums[i] != 0)
      nums[curr++] = nums[i];
  }
  for (int j = curr; j < N; ++j)
    nums[j] = 0;
}

int main() {
  std::vector<int> nums {0,1,0,3,12};
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
  moveZeroes(nums);
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
}
