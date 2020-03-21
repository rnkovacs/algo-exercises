/* Given an array of integers, return indices of the two numbers that
 * add up to a specific target. You may assume that each input would
 * have exactly one solution, and you may not use the same element twice.
 *
 * Example: nums = [2, 7, 11, 15], target = 9,
 *          return [0, 1], because nums[0] + nums[1] = 9.
 *
 * Runtime: 8 ms, faster than 93.08% of C++ online submissions.
 * Memory usage: 9.8 MB, less than 57.49% of C++ online submissions.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
  // 2 7 11 15, t = 9
  std::unordered_map<int, int> diffs;
  // 7 -> 0
  for (int i = 0, N = nums.size(); i < N; ++i) {
    if (diffs.count(nums[i]))
      return { diffs[nums[i]], i };

    diffs.insert({ target - nums[i], i });
  }

  return {};
}

int main() {
  std::vector<int> nums {2, 7, 11, 15};
  for (int i: nums) std::cout << i << ' ';
  std::cout << "\ntarget: 9\n";
  for (int i: twoSum(nums, 9)) std::cout << i << ' ';
  std::cout << '\n';
}
