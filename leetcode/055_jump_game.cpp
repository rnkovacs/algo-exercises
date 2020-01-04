/* Given an array of non-negative integers, you are initially positioned
 * at the first index of the array. Each element in the array represents
 * your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * Runtime: 12 ms, faster than 71.97% of C++ online submissions.
 * Memory usage: 9.9 MB, less than 93.42% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums) {
  int N = nums.size();
  if (!N) return false;
  
  std::vector<bool> dp(N, false);
  dp[0] = true;
  
  int maxIdx = 0;
  for (int i=1; i<N; i++) {
    int dist = i - maxIdx;
    
    if (dp[maxIdx] && nums[maxIdx] >= dist)
      dp[i] = true;
    
    if (nums[maxIdx] - dist < nums[i])
      maxIdx = i;
  }
  
  return dp[N-1];
}

int main() {
  std::vector<int> n {2,3,1,1,4};
  for (int i: n) std::cout << i << ' ';
  std::cout << "\ncanJump: " << canJump(n) << '\n';
  
  std::vector<int> m {3,2,1,0,4};
  for (int i: m) std::cout << i << ' ';
  std::cout << "\ncanJump: " << canJump(m) << '\n';
}
