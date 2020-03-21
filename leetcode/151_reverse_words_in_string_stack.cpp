/* Given an input string, reverse the string word by word.
 *
 * Runtime: 8 ms, faster than 77.43% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <stack>

std::string reverseWords(std::string s) {
  std::stack<std::string> st;
  
  int start = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != ' ' && start == -1)
      start = i;
    if (s[i] == ' ' && start != -1) {
      st.push(s.substr(start, i - start));
      start = -1;
    }
  }
  if (start != -1) st.push(s.substr(start, s.size() - start));
  
  if (st.empty()) return "";
  
  std::string res;
  while (!st.empty()) {
    res += st.top();
    st.pop();
    if (!st.empty()) res += ' ';
  }
  
  return res;
}

int main() {
  std::cout << "\"the sky is blue\"\n"
            << reverseWords("the sky is blue") << '\n';
  std::cout << "\n\"  hello world!  \"\n"
            << reverseWords("  hello world!  ") << '\n';
}
