/* Given an integer array nums, find the contiguous subarray (containing
 * at least one number) that has the largest sum and return its sum.
 *
 * Example: Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 *          Output: 6
 *          Explanation: [4, -1, 2, 1] has the largest sum 6.
 *
 * Runtime: 836 ms, faster than 5.01% of C++ online submissions.
 * Memory usage: 9.4 MB, less than 33.33% of C++ online submissions.
 *
 * dynamic_programming/53_maximum_subarray.cpp is much more efficient.
 */

#include <iostream>
#include <vector>

int largest_sum(std::vector<int> &nums, int l, int r) {
  if (r <= l)
      return nums[l];
  
  int m = (r - l) / 2 + l;

  int lmax = largest_sum(nums, l, m);
  int rmax = largest_sum(nums, m + 1, r);
  int one_side_max = (lmax > rmax) ? lmax : rmax;

  int mlmax = nums[m];
  int mrmax = nums[m+1];
  for (int i=m, suml=0; i>=0; --i) {
      suml += nums[i];
      mlmax = (suml > mlmax) ? suml : mlmax;
  }
  for (int i=m+1, sumr=0; i<nums.size(); ++i) {
      sumr += nums[i];
      mrmax = (sumr > mrmax) ? sumr : mrmax;
  }
  int middle_max = mlmax + mrmax;

  return (one_side_max > middle_max) ? one_side_max : middle_max;
}

int largest_sum(std::vector<int> &nums) {
  return largest_sum(nums, 0, nums.size() - 1);
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
