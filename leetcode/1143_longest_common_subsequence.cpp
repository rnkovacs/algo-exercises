/* Given two strings text1 and text2, return the length of their longest
 * common subsequence.
 *
 * Runtime: 12 ms, faster than 88.95% of C++ online submissions.
 * Memory usage: 14.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int longestCommonSubsequence(std::string text1, std::string text2) {
  int N = text1.size();
  int M = text2.size();
  if (!N || !M) return 0;
  
  std::vector<std::vector<int>> lcs(N+1);
  for (int i=0; i<=N; i++) lcs[i] = std::vector<int>(M+1, 0);
  
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=M; j++) {
      if (text1[i-1] == text2[j-1])
        lcs[i][j] = lcs[i-1][j-1] + 1;
      else
        lcs[i][j] = std::max(lcs[i][j-1], lcs[i-1][j]);
    }
  }
  
  return lcs[N][M];
}

int main() {
  std::cout << "abcde ace " << longestCommonSubsequence("abcde", "ace") << '\n';
  std::cout << "abc abc " << longestCommonSubsequence("abc", "abc") << '\n';
  std::cout << "abc def " << longestCommonSubsequence("abc", "def") << '\n';
}
