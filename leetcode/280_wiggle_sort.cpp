/* Given an unsorted array nums, reorder it in-place such that
 * nums[0] <= nums[1] >= nums[2] <= nums[3]....
 *
 * Runtime: 36 ms, faster than 56.02% of C++ online submissions.
 * Memory usage: 9 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

void wiggleSort(std::vector<int> &nums) {
  int N = nums.size();
  if (N < 2) return;
  
  std::sort(nums.begin(), nums.end());
  
  for (int i = 1; i < N - 1; i += 2)
    std::swap(nums[i], nums[i+1]);
}

int main() {
  std::vector<int> nums {3,5,2,1,6,4};
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
  wiggleSort(nums);
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
}
