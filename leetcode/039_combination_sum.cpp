/* Given a set of candidate numbers (without duplicates), and a target number,
 * find all unique combinations in candidates where the candidate numbers sum
 * to target. The same number may be chosen unlimited number of times.
 *
 * Runtime: 12 ms, faster than 83.35% of C++ online submissions.
 * Memory usage: 10.6 MB, less than 50.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

void findNums(std::vector<std::vector<int>> &res, std::vector<int> curr,
              const std::vector<int> &cands, int target, int idx) {
    if (target == 0) {
        std::sort(curr.begin(), curr.end());
        res.emplace_back(std::move(curr));
        return;
    }
    
    for (int i=idx, sz=cands.size(); i<sz; i++) {
        if (target >= cands[i]) {
            curr.push_back(cands[i]);
            findNums(res, curr, cands, target - cands[i], i);
            curr.pop_back();
        }
    }
}

std::vector<std::vector<int>>
combinationSum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    findNums(result, current, candidates, target, 0);
    
    return result;
}

int main() {
  std::vector<int> cand {2,3,6,7};
  auto v = combinationSum(cand, 7);
  for (auto list : v) {
    for (int i : list) std::cout << i << ' ';
    std::cout << '\n';
  }
}
