/* Given an integer array nums, find the sum of the elements between
 * indices i and j (i ≤ j), inclusive.
 *
 * Note:
 * 1. You may assume that the array does not change.
 * 2. There are many calls to sumRange function.
 *
 * Runtime: 44 ms, faster than 25.89% of C++ online submissions.
 * Memory usage: 14.8 MB, less than 100.00% of C++ online submissions.
 */

#include <vector>

class NumArray {
  std::vector<int> sums;
    
public:
  NumArray(std::vector<int> &nums) : sums(nums.size(), 0) {
    if (nums.empty()) return;
    
    sums[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
      sums[i] = sums[i - 1] + nums[i];
  }
  
  int sumRange(int i, int j) {
    if (i == 0) return sums[j];
    return sums[j] - sums[i - 1];
  }
};
