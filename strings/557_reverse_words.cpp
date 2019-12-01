/* Given a string, reverse the order of the characters in each word within
 * a sentence while preserving whitespace and initial word order.
 *
 * Runtime: 20 ms, faster than 85.11% of C++ online submissions.
 * Memory usage: 11.8 MB, less than 91.30% of C++ online submissions. 
 */

#include <iostream>

void reverseWord(std::string &s, int l, int r) {
  for ( ; l < r; l++, r--) {
    char tmp = s[r];
    s[r] = s[l];
    s[l] = tmp;
  }
}

std::string reverseWords(std::string s) {
  int len = s.size();
  if (len < 2) return s;
  
  int i = 0;
  int start;
  while (i < len) {
    while (s[i] == ' ' && i < len) i++;
    start = i;
    while (s[i] != ' ' && i < len) i++;
    reverseWord(s, start, i-1);
  }
  
  return s;
}

int main() {
  std::string s = "Let's take LeetCode contest";
  std::cout << s << '\n' << reverseWords(s) << "\n\n";
}
