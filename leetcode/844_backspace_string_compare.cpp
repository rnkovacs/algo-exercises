/* Given two strings S and T, return if they are equal when both are typed
 * into empty text editors. # means a backspace character.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

int process(std::string &s) {
  int j = 0;
  int i = 0;
  while (i < s.size()) {
    if (s[i] != '#') {
      s[j++] = s[i++];
    } else {
      if (j > 0) --j;
      ++i;
    }
  }
  return j;
}

bool backspaceCompare(std::string S, std::string T) {
  int sLen = process(S);
  S = S.substr(0, sLen);
  int tLen = process(T);
  T = T.substr(0, tLen);
  return S == T;
}

int main() {
  std::cout << "ab#c ad#c " << backspaceCompare("ab#c", "ad#c") << '\n';
}
