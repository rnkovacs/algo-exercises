/* Given an input string, reverse the string word by word.
 *
 * Runtime: 12 ms, faster than 36.42% of C++ online submissions.
 * Memory usage: 7.6 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>

std::string trimSpaces(const std::string &s) {
  int N = s.size();
  
  int firstChar = 0;
  int lastChar = N - 1;
  
  while (s[firstChar] == ' ' && firstChar < N) ++firstChar;
  if (firstChar == N) return "";

  while (s[lastChar] == ' ' && lastChar >= 0) --lastChar;
  
  bool space = false;
  std::string res;
  for (int i = firstChar; i <= lastChar; ++i) {
    if (s[i] == ' ' &&  space) continue; // skip not-first spaces

    if (s[i] == ' ' && !space) space = true;  // first space
    if (s[i] != ' ' &&  space) space = false; // first char

    res += s[i];
  }
  return res;
}

std::string reverseWords(std::string s) {
  std::string res = trimSpaces(s);
  if (res.empty()) return res;
  
  std::reverse(res.begin(), res.end());
  
  int start = 0;
  int M = res.size();
  for (int i = 1; i < M; ++i) {
    if (res[i] == ' ') {
      std::reverse(res.begin() + start, res.begin() + i);
      start = -1;
    }
    else if (start == -1) start = i;
  }
  std::reverse(res.begin() + start, res.begin() + M);
  
  return res;
}

int main() {
  std::cout << "\"the sky is blue\"\n"
            << reverseWords("the sky is blue") << '\n';
  std::cout << "\n\"  hello world!  \"\n"
            << reverseWords("  hello world!  ") << '\n';
}
