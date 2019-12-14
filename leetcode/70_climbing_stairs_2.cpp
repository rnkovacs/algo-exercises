/* You are climbing a stair case. It takes n steps to reach the top.
 * Each time you can climb 1 or 2 steps. In how many distinct ways can you
 * climb to the top?
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.3 MB, less than 89.71% of C++ online submissions.
 */

#include <iostream>

int climbStairs(int n) {
  if (n < 2)
    return 1;
  
  int prev1 = 1;
  int prev2 = 2;
  int current = prev2;
  for (int i=2; i<n; ++i) {
    current = prev1 + prev2;
    prev1 = prev2;
    prev2 = current;
  }

  return current;
}

int main() {
  std::cout << "# of ways to climb 1 stair: " << climbStairs(1) << '\n';
  std::cout << "# of ways to climb 2 stairs: " << climbStairs(2) << '\n';
  std::cout << "# of ways to climb 3 stairs: " << climbStairs(3) << '\n';
  std::cout << "# of ways to climb 4 stairs: " << climbStairs(4) << '\n';
  std::cout << "# of ways to climb 5 stairs: " << climbStairs(5) << '\n';
  std::cout << "# of ways to climb 6 stairs: " << climbStairs(6) << '\n';
}
