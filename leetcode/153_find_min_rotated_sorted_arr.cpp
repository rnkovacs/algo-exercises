/* Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand. Find the minimum element.
 *
 * Complexity: O(log N).
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.7 MB, less than 84.44% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
  int N = nums.size();
  if (N == 1) return nums[0];
  
  int first = nums[0];
  int last = nums[N-1];
  if (last >= first) return first;
  
  // last < first
  int l = 0;
  int r = N - 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (nums[m] >= first) {
      l = m + 1;
    } else { // nums[m] <= last
      r = m;
    }
    if (l == r) return nums[l];
  }
  
  return -1;
}

int main() {
  std::vector<int> nums {3,4,5,1,2};
  for (int i: nums) std::cout << i << ' ';
  std::cout << "\nMin: " << findMin(nums) << "\n\n";
  
  std::vector<int> nums2 {4,5,6,7,0,1,2};
  for (int i: nums2) std::cout << i << ' ';
  std::cout << "\nMin: " << findMin(nums2) << "\n";
}
