/* Given a string s and a string t, check if s is subsequence of t.
 *
 * You may assume that there is only lower case English letters in both
 * s and t. t is potentially a very long (length ~= 500,000) string, and
 * s is a short string (<=100).
 *
 * A subsequence of a string is a new string which is formed from the
 * original string by deleting some (can be none) of the characters
 * without disturbing the relative positions of the remaining characters.
 * (ie, "ace" is a subsequence of "abcde" while "aec" is not).
 *
 * Runtime: 60 ms, faster than 83.01% of C++ online submissions.
 * Memory usage: 15.1 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

bool isSubsequence(std::string s, std::string t) {
  int N = t.size();
  int M = s.size();
  
  if (N < M) return false;
  
  int i = 0;
  int j = 0;
  
  while (j < M && i < N) {
    if (t[i] == s[j]) ++j;
    ++i;
  }
  
  if (j == M) return true;
  
  return false;
}

int main() {
  std::cout << "abc is subsequence of ahbgdc: "
            << isSubsequence("abc", "ahbgcd") << '\n';
  std::cout << "axc is subsequence of ahbgdc: "
            << isSubsequence("axc", "ahbgcd") << '\n';
}
