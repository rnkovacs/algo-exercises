/* There is a fence with n posts, each post can be painted with one of the
 * k colors. You have to paint all the posts such that no more than two
 * adjacent fence posts have the same color. Return the total number of ways
 * you can paint the fence.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

int numWays(int n, int k) {
  if (n == 0) return 0;
  if (n == 1) return k;
  if (n == 2) return k * k;

  int prev = k * k;
  int curr;
  int dup = k;

  for (int i = 2; i < n; ++i) {
    curr = dup * (k - 1) + (prev - dup) * k;
    dup = prev - dup;
    prev = curr;
  }
  
  return curr;
}

int main() {
  std::cout << numWays(3, 2) << '\n';
}
