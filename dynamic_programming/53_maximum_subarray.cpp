/* Given an integer array nums, find the contiguous subarray (containing
 * at least one number) that has the largest sum and return its sum.
 *
 * Example: Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 *          Output: 6
 *          Explanation: [4, -1, 2, 1] has the largest sum 6.
 *
 * Runtime: 4 ms, faster than 98.51% of C++ online submissions.
 * Memory usage: 9.3 MB, less than 70.59% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int largest_sum(std::vector<int> &nums) {
  int max_sum = nums[0];
  int sum = max_sum;
  for (int i=0, len=nums.size(); i<len; ++i) {
    sum = (nums[i] > sum + nums[i]) ? nums[i] : (sum + nums[i]);
    max_sum = (sum > max_sum) ? sum : max_sum;
  }
  return max_sum;
}

int main() {
  std::vector<int> nums1 {-2,1,-3,4,-1,2,1,-5,4};
  int sum = largest_sum(nums1);
  for (int elem : nums1) std::cout << elem << ' ';
  std::cout << '\n' << sum << "\n\n";
  
  std::vector<int> nums2 {-2};
  sum = largest_sum(nums2);
  for (int elem : nums2) std::cout << elem << ' ';
  std::cout << '\n' << sum << "\n\n";
  
  std::vector<int> nums3 {-2, 2, -2, 2};
  sum = largest_sum(nums3);
  for (int elem : nums3) std::cout << elem << ' ';
  std::cout << '\n' << sum << '\n';
}
