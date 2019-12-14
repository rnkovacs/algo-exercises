/* You are climbing a stair case. It takes n steps to reach the top.
 * Each time you can climb 1 or 2 steps. In how many distinct ways can you
 * climb to the top?
 *
 * Runtime: 4 ms, faster than 51.30% of C++ online submissions.
 * Memory usage: 8.2 MB, less than 98.53% of C++ online submissions.
 */

#include <iostream>

int climbStairs(int n) {
  if (n < 2)
    return 1;
  
  int ways[n];
  ways[0] = 1;
  ways[1] = 2;
  for (int i=2; i<n; ++i)
    ways[i] = ways[i-1] + ways[i-2];

  return ways[n-1];
}

int main() {
  std::cout << "# of ways to climb 1 stair: " << climbStairs(1) << '\n';
  std::cout << "# of ways to climb 2 stairs: " << climbStairs(2) << '\n';
  std::cout << "# of ways to climb 3 stairs: " << climbStairs(3) << '\n';
  std::cout << "# of ways to climb 4 stairs: " << climbStairs(4) << '\n';
  std::cout << "# of ways to climb 5 stairs: " << climbStairs(5) << '\n';
  std::cout << "# of ways to climb 6 stairs: " << climbStairs(6) << '\n';
}
