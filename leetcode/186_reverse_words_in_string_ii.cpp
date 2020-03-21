/* Given an input string, reverse the string word by word.
 *
 * - A word is defined as a sequence of non-space characters.
 * - The input string does not contain leading or trailing spaces.
 * - The words are always separated by a single space.
 *
 * Runtime: 76 ms, faster than 13.68% of C++ online submissions.
 * Memory usage: 14 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

void reverseWords(std::vector<char> &s) {
  if (s.empty()) return;
  
  std::reverse(s.begin(), s.end());
  
  //[e u l b _ s i _ y k s _ e h t]
  int start = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == ' ') {
      std::reverse(s.begin() + start, s.begin() + i);
      start = -1;
    }
    if (s[i] != ' ' && start == -1)
      start = i;
  }
  std::reverse(s.begin() + start, s.begin() + s.size());
}

int main() {
  std::vector<char> v {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ',
                       'i', 's', ' ', 'b', 'l', 'u', 'e'};
  for (char c: v) std::cout << c << ' '; std::cout << '\n';
  reverseWords(v);
  for (char c: v) std::cout << c << ' '; std::cout << '\n';
}
