/* You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security system connected and it will automatically contact the police
 * if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money
 * of each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Runtime: 0 ms (?), faster than 100.00% of C++ online submissions.
 * Memory usage: 8.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int rob(std::vector<int>& nums) {
  int N = nums.size();
  if (N == 0) return 0;
  if (N == 1) return nums[0];
  
  std::vector<int> amount (N, 0);
  amount[0] = nums[0];
  amount[1] = nums[0] > nums[1] ? nums[0] : nums[1];
  for (int i=2; i<N; ++i) {
    amount[i] = std::max(amount[i-1], amount[i-2] + nums[i]);
  }
  
  return amount[N-1];
}

int main() {
  std::vector<int> houses {1,2,3,1};
  for (int i : houses) std::cout << i << ' ';
  std::cout << "\nMax I can rob: " << rob(houses) << '\n';
}
