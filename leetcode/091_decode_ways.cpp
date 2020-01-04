/* A message containing letters from A-Z is being encoded to numbers
 * using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total
 * number of ways to decode it.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 82.35% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int numDecodings(std::string s) {
  int N = s.size();
  if (!N || s[0] == '0') return 0;
  if (N == 1) return 1;
  
  std::vector<int> dp(N, 0);
  dp[0] = 1;
  if (s[1] == '0' && s[0] != '1' && s[0] != '2')
    return 0;
  dp[1] = (   (s[0] == '1' && s[1] >= '1' && s[1] <= '9')
           || (s[0] == '2' && s[1] >= '1' && s[1] <= '6'))
          ? 2
          : 1;
  
  for (int i=2; i<N; i++) {
    char first = s[i-1];
    char sec = s[i];
    
    if (sec == '0' && first != '1' && first != '2')
      return 0;
    
    if (sec != '0')
      dp[i] = dp[i-1];

    if (   (first == '1' && sec >= '1' && sec <= '9')
        || (first == '2' && sec >= '1' && sec <= '6')
        || (sec == '0'))
      dp[i] += dp[i-2];
  }
  
  return dp[N-1];
}

int main() {
  std::cout << "12 : " << numDecodings("12") << '\n';
  std::cout << "226 : " << numDecodings("226") << '\n';
}
