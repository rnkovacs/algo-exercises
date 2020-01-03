/* Given a string s, find the longest palindromic substring in s.
 *
 * Runtime: 20 ms, faster than 76.88% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 73.79% of C++ online submissions.
 */

#include <iostream>

std::string longestPalindrome(std::string s) {
  int sz = s.size();
  int start = 0;
  int end = 0;
  for (int i=0, sz=s.size(); i<sz; i++) {
    // Look for odd-size substring from i as center.
    int l = i; int r = i;
    while (l >= 0 && r < sz && s[l] == s[r]) { l--; r++; }
    int len1 = r - l - 1;

    // Look for even-size substring from i and i+1 as center.
    l = i; r = i+1;
    while (l >= 0 && r < sz && s[l] == s[r]) { l--; r++; }
    int len2 = r - l - 1;
    
    int len = std::max(len1, len2);
    if (len > end - start) {
      start = i - (len - 1) / 2;
      end = i + len / 2;
    }
  }
  return s.substr(start, end - start + 1);
}

int main() {
  std::cout << "babad : " << longestPalindrome("babad") << '\n'; 
  std::cout << "cbbd : " << longestPalindrome("cbbd") << '\n'; 
}
