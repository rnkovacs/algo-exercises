/*
 * Runtime: 0 ms (???), faster than 100.00% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 80.62% of C++ online submissions.
 */

#include <iostream>
#include <stack>

char opening(char c) {
  switch (c) {
    case ')': return '(';
    case ']': return '[';
    case '}': return '{';
    default: return '\0';
  }
}

bool is_valid(std::string s) {
  if (s.empty())
    return true;

  std::stack<char> st;
  for (char c : s) {
    if (!st.empty() && st.top() == opening(c))
      st.pop();
    else
      st.push(c);
  }

  if (st.empty())
    return true;

  return false;
}

int main() {
  std::string s = "()";
  std::cout << s << "\nvalid: " << is_valid(s) << "\n\n";

  s = "()[]{}";
  std::cout << s << "\nvalid: " << is_valid(s) << "\n\n";

  s = "([)]";
  std::cout << s << "\nvalid: " << is_valid(s) << "\n\n";

  s = "{[]}";
  std::cout << s << "\nvalid: " << is_valid(s) << "\n\n";
}
