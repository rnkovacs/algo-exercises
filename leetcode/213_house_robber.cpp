/* You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed. All houses at this
 * place are arranged in a circle. That means the first house is the neighbor
 * of the last one. Meanwhile, adjacent houses have security system connected
 * and it will automatically contact the police if two adjacent houses were
 * broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money
 * of each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 97.14% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int rob(std::vector<int>& nums) {
  int N = nums.size();
  if (!N) return 0;
  if (N == 1) return nums[0];
  if (N == 2) return std::max(nums[0], nums[1]);
  
  std::vector<int> dp1(N-1, 0);
  std::vector<int> dp2(N-1, 0);
  
  dp1[0] = nums[0];
  dp1[1] = std::max(nums[0], nums[1]);
  for (int i=2; i<(N-1); i++)
    dp1[i] = std::max(dp1[i-1], dp1[i-2] + nums[i]);

  dp2[0] = nums[1];
  dp2[1] = std::max(nums[1], nums[2]);
  for (int i=2; i<(N-1); i++)
    dp2[i] = std::max(dp2[i-1], dp2[i-2] + nums[i + 1]);
  
  return std::max(dp1[N-2], dp2[N-2]);
}

int main() {
  std::vector<int> n {2,3,2};
  for (int i: n) std::cout << i << ' ';
  std::cout << "\nRob: " << rob(n) << '\n';

  std::vector<int> m {1,2,3,1};
  for (int i: m) std::cout << i << ' ';
  std::cout << "\nRob: " << rob(m) << '\n';
}
