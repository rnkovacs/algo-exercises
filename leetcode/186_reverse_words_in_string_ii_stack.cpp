/* Given an input string, reverse the string word by word.
 *
 * - A word is defined as a sequence of non-space characters.
 * - The input string does not contain leading or trailing spaces.
 * - The words are always separated by a single space.
 *
 * Runtime: 76 ms, faster than 13.68% of C++ online submissions.
 * Memory usage: 14.4 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

void reverseWords(std::vector<char> &s) {
  if (s.empty()) return;
  
  std::stack<std::string> st;
  bool word = false;
  std::string tmp;
  
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != ' ') {
      if (!word) { // first char in word
        tmp = s[i];
        word = true;
      } 
      else tmp += s[i]; // other chars in word
    }
    else { // end of a word (space)
      st.push(tmp);
      word = false;
    }
  }
  st.push(tmp);
  
  s = {};
  while (!st.empty()) {
    tmp = st.top();
    for (char c: tmp) s.push_back(c);
    st.pop();
    if (!st.empty()) s.push_back(' ');
  }
}

int main() {
  std::vector<char> v {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ',
                       'i', 's', ' ', 'b', 'l', 'u', 'e'};
  for (char c: v) std::cout << c << ' '; std::cout << '\n';
  reverseWords(v);
  for (char c: v) std::cout << c << ' '; std::cout << '\n';
}
