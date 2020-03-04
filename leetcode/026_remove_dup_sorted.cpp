/* Given a sorted array nums, remove the duplicates in-place such that
 * each element appears only once and return the new length.
 *
 * Runtime: 40 ms, faster than 25.02% of C++ online submissions.
 * Memory usage: 9.9 MB, less than 87.50% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums) {
  int N = nums.size();
  if (!N || N == 1) return N;
  
  int j = 1;
  for (int i = 1; i < N; i++) {
    if (nums[i] != nums[i-1])
      nums[j++] = nums[i];
  }
  
  return j;
}

int main() {
  std::vector<int> nums {0,0,1,1,1,2,2,3,3,4};
  for (int i: nums) std::cout << i << ' ';
  std::cout << '\n';

  int lim = removeDuplicates(nums);
  for (int i = 0; i < lim; i++) std::cout << nums[i] << ' ';
  std::cout << '\n';
}
