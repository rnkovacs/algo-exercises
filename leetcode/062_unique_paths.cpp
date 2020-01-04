/* A robot is located at the top-left corner of a m x n grid.
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid.
 * How many possible unique paths are there?
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.8 MB, less than 31.25% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
  if (!n || !m) return 0;
  if (m == 1 || n == 1) return 1;
  
  std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
  
  for (int j=0; j<m; j++) dp[0][j] = 1;
  for (int i=0; i<n; i++) dp[i][0] = 1;
  
  for (int i=1; i<n; i++) {
    for (int j=1; j<m; j++) {
      dp[i][j] = dp[i][j-1] + dp[i-1][j];
    }
  }
  
  return dp[n-1][m-1];
}

int main() {
  std::cout << "2 x 3\nunique paths: " << uniquePaths(3,2) << '\n';
}
