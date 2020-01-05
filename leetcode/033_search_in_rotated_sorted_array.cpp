/* Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand. You are given a target value to search.
 * If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Runtime: 4 ms, faster than 81.36% of C++ online submissions.
 * Memory usage: 8.7 MB, less than 87.95% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int search(std::vector<int> &nums, int target) {
  int N = nums.size();
  if (!N) return -1;

  int first = nums[0];
  int last = nums[N-1];
  bool rotated = first > last;
  
  int l = 0;
  int r = N - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) {
      return m;
    } else if (nums[m] < target) {
      if (rotated && nums[m] <= last && target >= first)
        r = m - 1;
      else
        l = m + 1;
    } else { // nums[m] > target
      if (rotated && nums[m] >= first && target <= last)
        l = m + 1;
      else
        r = m - 1;
    }
  }
  
  return -1;
}

int main() {
  std::vector<int> nums {4,5,6,7,0,1,2};
  for (int i: nums) std::cout << i << ' ';
  std::cout << "\nTarget: 0, index: " << search(nums, 0) << '\n';
  std::cout << "Target: 3, index: " << search(nums, 3) << '\n';
}
