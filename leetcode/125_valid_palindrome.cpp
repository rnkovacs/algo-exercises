/* Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Runtime: 8 ms, faster than 85.53% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 100.00% of C++ online submissions.
 */

#include <cctype>
#include <iostream>

bool isPalindrome(std::string s) {
  int len = s.size();
  if (len < 2) return true;

  int l = 0;
  int r = len - 1;
  while (l < r) {
    if (!std::isalnum(s[l])) { ++l; continue; }
    if (!std::isalnum(s[r])) { --r; continue; }
    if (std::tolower(s[l++]) != std::tolower(s[r--])) return false;
  }
  
  return true;
}

int main() {
  std::string s = "A man, a plan, a canal: Panama";
  std::cout << s << '\n' << isPalindrome(s) << '\n';
}
