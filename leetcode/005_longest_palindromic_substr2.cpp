/* Given a string s, find the longest palindromic substring in s.
 *
 * Runtime: 48 ms, faster than 51.63% of C++ online submissions.
 * Memory usage: 6.6 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

void expandAround(const std::string &s, int i1, int i2, int &maxLen, int &begin) {
  int N = s.size();
  for (int j = 0; (i1 - j) >= 0 && (i2 + j) < N; ++j) {
    if (s[i1 - j] != s[i2 + j])
      break;
    
    int len = 2 * j + 1;
    if (i1 != i2) ++len;
    
    if (len > maxLen) {
      maxLen = len;
      begin = i1 - j;
    }
  }
}
  
std::string longestPalindrome(std::string s) {
  if (s.empty()) return s;
  
  int N = s.size();
  int begin = 0;
  int maxLen = 0;
  
  for (int i = 0; i < N; ++i) {
    expandAround(s, i, i, maxLen, begin);
    expandAround(s, i, i + 1, maxLen, begin);
  }
  
  return s.substr(begin, maxLen);
}

int main() {
  std::cout << "babad : " << longestPalindrome("babad") << '\n'; 
  std::cout << "cbbd : " << longestPalindrome("cbbd") << '\n'; 
}
