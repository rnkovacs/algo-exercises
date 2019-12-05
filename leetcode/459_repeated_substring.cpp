/* Given a non-empty string, check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together.
 *
 * Examples: Input: "abab"  Output: true
 *           Input: "aba"   Output: false
 *
 * Runtime: 8 ms, faster than 99.79% of C++ online submissions.
 * Memory usage: 12.8 MB, less than 85.71% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool repeatedSubstringPattern(std::string s) {
  int len = s.size();
  if (len < 2)
    return false;

  char pfirst = s[0];
  char plast = s[len-1];
  std::vector<std::string> patterns;

  for (int i = len/2; i > 0; --i) {
    if (!(len % i) && s[i-1] == plast)
      patterns.push_back(s.substr(0, i));
  }
  
  for (std::string pattern : patterns) {
    int plen = pattern.size();
    for (int i=plen; i<len; i+=plen) {
      if (s.substr(i, plen) != pattern)
        break;
      if (i+plen == len)
        return true;
    }
  }
  
  return false;
}

int main() {
  std::string s = "babbabbabbabbab";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << "\n\n";
  
  s = "a";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << "\n\n";
  
  s = "aa";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << "\n\n";
  
  s = "ab";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << "\n\n";
  
  s = "abc";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << "\n\n";
  
  s = "abcabc";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << "\n\n";
  
  s = "abca";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << "\n\n";
  
  s = "abaaabaa";
  std::cout << "\"" << s << "\"\n" << repeatedSubstringPattern(s) << '\n';
}
