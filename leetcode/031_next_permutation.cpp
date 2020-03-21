/* Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Runtime: 4 ms, faster 98.85% of C++ online submissions.
 * Memory usage: 7.7 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void nextPermutation(std::vector<int> &nums) {
  int n = nums.size();
  if (n < 2) return;

  // Last two elements are increasing.
  if (nums[n - 2] < nums[n - 1]) {
    std::swap(nums[n - 2], nums[n - 1]);
    return;
  }

  int localMax = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    // find first local max from behind; we will replace it
    if (nums[i] < nums[i + 1]) {
      localMax = i + 1; // n - 2 = 1
      // we need the lexicographical successor of max-1 among [max, end]
      std::sort(nums.begin() + localMax, nums.end());
      auto it = std::upper_bound(nums.begin() + localMax, nums.end(),
                                 nums[localMax - 1]);

      // swap it with max-1
      std::swap(*it, nums[localMax - 1]);

      // sort again from max to end
      std::sort(nums.begin() + localMax, nums.end());
      return;
    }
  }

  std::reverse(nums.begin(), nums.end());
}

int main() {
  std::vector<int> nums { 1, 2, 3 };
  for (int i : nums) std::cout << i << ' '; std::cout << '\n';
  nextPermutation(nums);
  for (int i : nums) std::cout << i << ' '; std::cout << '\n';
  
  std::vector<int> nums2 { 3, 2, 1 };
  for (int i : nums2) std::cout << i << ' '; std::cout << '\n';
  nextPermutation(nums2);
  for (int i : nums2) std::cout << i << ' '; std::cout << '\n';
  
  std::vector<int> nums3 { 1, 1, 5 };
  for (int i : nums3) std::cout << i << ' '; std::cout << '\n';
  nextPermutation(nums3);
  for (int i : nums3) std::cout << i << ' '; std::cout << '\n';
}
