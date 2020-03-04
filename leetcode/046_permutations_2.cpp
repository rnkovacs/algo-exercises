/* Given a collection of distinct integers, return all possible permutations.
 *
 * Runtime: 8 ms, faster than 98.76% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void permute(int idx, std::vector<int> &nums,
             std::vector<std::vector<int>> &result) {
    if (idx == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    
    for (int i = idx, N = nums.size(); i < N; ++i) {
        std::swap(nums[i], nums[idx]);
        permute(idx + 1, nums, result);
        std::swap(nums[i], nums[idx]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return {{}};
    if (N == 1) return {nums};
    
    std::vector<std::vector<int>> result;
    permute(0, nums, result);
    return result;
}

int main() {
  std::vector<int> nums {1, 2, 3};
  for (const std::vector<int> &perm : permute(nums)) {
    for (int i : perm) std::cout << i << ' ';
    std::cout << '\n';
  }
}
