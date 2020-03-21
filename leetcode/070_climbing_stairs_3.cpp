/* Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

int climbStairs(int n) {
  if (n < 2) return n;
  
  int prev = 1;
  int curr = 2;
  for (int i = 3; i <= n; ++i) {
    int oldCurr = curr;
    curr += prev;
    prev = oldCurr;
  }
  
  return curr;
}

int main() {
  std::cout << "# of ways to climb 2 stairs: " << climbStairs(2) << '\n';
  std::cout << "# of ways to climb 3 stairs: " << climbStairs(3) << '\n';
  std::cout << "# of ways to climb 4 stairs: " << climbStairs(4) << '\n';
  std::cout << "# of ways to climb 5 stairs: " << climbStairs(5) << '\n';
  std::cout << "# of ways to climb 6 stairs: " << climbStairs(6) << '\n';
}
