/* Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Runtime: 20 ms, faster than 95.12% of C++ online submissions.
 * Memory usage: 9.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <unordered_set>
#include <vector>

void permuteUnique(std::vector<int> &nums,
                   std::vector<std::vector<int>> &res, int idx) {
  if (idx == nums.size() - 1) {
    res.emplace_back(nums);
    return;
  }
  
  std::unordered_set<int> unique;
  for (int i = idx, n = nums.size(); i < n; ++i) {
    if (unique.find(nums[i]) == unique.end()) {
      std::swap(nums[i], nums[idx]);
      permuteUnique(nums, res, idx + 1);
      std::swap(nums[i], nums[idx]);
      unique.insert(nums[i]);
    }
  }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
  if (nums.empty()) return {{ }};
  if (nums.size() == 1) return {{ nums[0] }};
  
  std::vector<std::vector<int>> res;
  permuteUnique(nums, res, 0);
  return res;
}

int main() {
  std::vector<int> nums { 1, 1, 2 };
  for (const auto &v : permuteUnique(nums)) {
    for (int i : v) std::cout << i << ' ';
    std::cout << '\n';
  }
}
