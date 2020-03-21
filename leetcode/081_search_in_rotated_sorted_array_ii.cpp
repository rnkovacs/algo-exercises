/* Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 *
 * Runtime: 4 ms, faster than 98.75% of C++ online submissions.
 * Memory usage: 8.1 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool isAllIncreasing(const std::vector<int> &nums) {
  return nums[0] < nums[nums.size() - 1];
}

bool inFirstPart(const std::vector<int> &nums, int num, int idx) {
  if (num > nums[0]) return true;
  if (num < nums[0]) return false;
  while (--idx >= 0) {
    if (nums[idx] > nums[idx + 1])
      return false;
  }
  return true;
}

bool inFirstPart(const std::vector<int> &nums, int num) {
  return num >= nums[0];
}

bool search(std::vector<int> &nums, int target) {
  if (nums.empty()) return false;
  int N = nums.size();
  if (N == 1) return nums[0] == target;
  
  int l = 0;
  int r = N - 1;

  //       /           /|          rotated: nums[0] > nums[N-1]
  //      /           / |      not rotated: nums[0] < nums[N-1]
  //     /              |/          (only unique elements)
  
  // with duplicates: nums[0] can be == nums[N-1]
  
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) return true;

    // Array is not rotated and has at least two distinct elements.
    if (isAllIncreasing(nums)) {
      if (nums[m] < target) l = m + 1;
      else                  r = m - 1;
      continue;
    }
    
    // Array is rotated or it has all the same elements.
    // nums[0] >= nums[N - 1]
    if (nums[m] < target) {
      if (inFirstPart(nums, nums[m], m)) l = m + 1;
      else {
        if (inFirstPart(nums, target)) r = m - 1;
        else                           l = m + 1;
      }
    }
    else { // nums[m] > target
      if (!inFirstPart(nums, nums[m], m)) r = m - 1;
      else {
        if (inFirstPart(nums, target)) r = m - 1;
        else                           l = m + 1;
      }
    }
  }
  
  return false;
}

int main() {
  std::vector<int> nums {2,5,6,0,0,1,2};
  for (int i: nums) std::cout << i << ' ';
  std::cout << "\n0 in array: " << search(nums, 0) << "\n\n";
  
  std::vector<int> nums2 {2,5,6,0,0,1,2};
  for (int i: nums2) std::cout << i << ' ';
  std::cout << "\n3 in array: " << search(nums2, 3) << '\n';
}
