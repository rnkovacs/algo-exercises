/* Given a string containing just the characters '(', ')', '{', '}',
 * '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.6 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <stack>

bool isOpeningOf(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isValid(std::string s) {
  if (s.empty()) return true;
  
  std::stack<char> st;
  for (char c: s) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
      continue;
    }
    
    if (st.empty() || !isOpeningOf(st.top(), c))
      return false;
    
    st.pop();
  }
  
  return st.empty();
}

int main() {
  std::string s = "()";
  std::cout << s << "\nvalid: " << isValid(s) << "\n\n";

  s = "()[]{}";
  std::cout << s << "\nvalid: " << isValid(s) << "\n\n";

  s = "([)]";
  std::cout << s << "\nvalid: " << isValid(s) << "\n\n";

  s = "{[]}";
  std::cout << s << "\nvalid: " << isValid(s) << "\n\n";
}
