/* Given a collection of distinct integers, return all possible permutations.
 *
 * Runtime: 8 ms, faster than 98.76% of C++ online submissions.
 * Memory usage: 9.4 MB, less than 68.55% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void permute(const std::vector<int> &prefix, const std::vector<int> &remainder,
             std::vector<std::vector<int>> &result) {
    if (remainder.size() == 0) {
        result.push_back(prefix);
        return;
    }
    
    for (int i=0, N=remainder.size(); i<N; ++i) {
        std::vector<int> newPrefix = prefix;
        newPrefix.push_back(remainder[i]);
        std::vector<int> newRemainder = remainder;
        newRemainder.erase(newRemainder.begin() + i);
        permute(newPrefix, newRemainder, result);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return {{}};
    if (N == 1) return {nums};
    
    std::vector<std::vector<int>> result;
    permute({}, nums, result);
    return result;
}

int main() {
  std::vector<int> nums {1, 2, 3};
  for (const std::vector<int> &perm : permute(nums)) {
    for (int i : perm) std::cout << i << ' ';
    std::cout << '\n';
  }
}
