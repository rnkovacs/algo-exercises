/*
 * Given an array of integers, return indices of the two numbers that add up
 * to a specific target. You may assume that each input would have exactly one
 * solution, and you may not use the same element twice.
 *
 * Example: nums = [2, 7, 11, 15], target = 9,
 *          return [0, 1], because nums[0] + nums[1] = 9.
 *
 * Runtime: 8 ms, faster than 92.94% of C++ online submissions.
 * Memory usage: 10.1 MB, less than 53.68% of C++ online submissions.
 */

#include <cassert>
#include <iostream>
#include <unordered_map>

std::pair<int, int> pair_with_sum(int *nums, int n, int target) {
  std::unordered_map<int, int> complements;
  for (int i=0; i<n; ++i) {
    int complement = target - nums[i];
    if (!complements.count(complement))
      complements[nums[i]] = i;
    else
      return {complements[complement], i};
  }
  assert(false && "Unreachable\n");
}

int main() {
  int nums1[] = {2, 7, 11, 15};
  int n = 4;
  int target = 18;

  std::pair<int, int> indexes = pair_with_sum(nums1, n, target);
  for (int elem : nums1) std::cout << elem << ' ';
  std::cout << "\nTarget: " << target << "\nIndexes: "
            << indexes.first << ' ' << indexes.second << "\n\n";

  int nums2[] = {1, 0};
  n = 2;
  target = 1;

  indexes = pair_with_sum(nums2, n, target);
  for (int elem : nums2) std::cout << elem << ' ';
  std::cout << "\nTarget: " << target << "\nIndexes: "
            << indexes.first << ' ' << indexes.second << "\n\n";

  int nums3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  n = 9;
  target = 17;

  indexes = pair_with_sum(nums3, n, target);
  for (int elem : nums3) std::cout << elem << ' ';
  std::cout << "\nTarget: " << target << "\nIndexes: "
            << indexes.first << ' ' << indexes.second << "\n\n";
}
