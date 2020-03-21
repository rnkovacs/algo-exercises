/* Given an integer array nums, find the contiguous subarray (containing
 * at least one number) that has the largest sum and return its sum.
 *
 * Example: Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 *          Output: 6
 *          Explanation: [4, -1, 2, 1] has the largest sum 6.
 *
 * Runtime: 8 ms, faster than 72.51% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int maxSubArray(std::vector<int> &nums) {
  if (nums.empty()) return 0;

  int localMax = nums[0];
  int globalMax = localMax;

  for (int i = 1; i < nums.size(); ++i) {
    localMax = std::max(localMax + nums[i], nums[i]);
    globalMax = std::max(localMax, globalMax);
  }
  
  return globalMax;
}

int main() {
  std::vector<int> nums1 {-2,1,-3,4,-1,2,1,-5,4};
  int sum = maxSubArray(nums1);
  for (int elem : nums1) std::cout << elem << ' ';
  std::cout << '\n' << sum << '\n';
}
