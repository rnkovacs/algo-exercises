/* You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 *
 * Runtime: 184 ms, faster than 20.85% of C++ online submissions.
 * Memory usage: 8 MB, less than 100.00% of C++ online submissions.
 */

#include <vector>

std::vector<int> countSmaller(std::vector<int> &nums) {
  if (nums.empty()) return {};
  
  int N = nums.size();
  std::vector<int> counts(N, 0);
  
  std::vector<int> s;
  s.push_back(nums[N - 1]);
  
  for (int i = N - 2; i >= 0; --i) {
    auto it = std::lower_bound(s.begin(), s.end(), nums[i]);
    counts[i] = std::distance(s.begin(), it);
    s.insert(it, nums[i]);
  }
  
  return counts;
}
