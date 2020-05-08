/* Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) that has the largest product.
 *
 * Runtime: 4 ms, faster than 89.70% of C++ online submissions.
 * Memory usage: 9 MB, less than 92.50% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int maxProduct(std::vector<int>& nums) {
  int N = nums.size();
  if (N == 0) return 0;
  if (N == 1) return nums[0];

  int maxProd = nums[0];
  int minProd = maxProd;
  int globMax = maxProd;

  // either nums[i] * maxProd
  //     or nums[i] * minProd  (if they are neg)
  //     or nums[i]

  for (int i=1; i<N; ++i) {
    int oldMax = maxProd;
    maxProd = std::max(nums[i] * maxProd, std::max(nums[i] * minProd, nums[i]));
    minProd = std::min(nums[i] * oldMax, std::min(nums[i] * minProd, nums[i]));
    globMax = (maxProd > globMax) ? maxProd : globMax;
  }
  
  return globMax;
}

int main() {
  std::vector<int> nums {2,3,-2,4};
  for (int i : nums) std::cout << i << ' ';
  std::cout << "\nMax subarray product: " << maxProduct(nums) << '\n';
}
