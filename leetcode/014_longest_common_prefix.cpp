/* Write a function to find the longest common prefix string amongst an
 * array of strings. If there is no common prefix, return an empty string "".
 *
 * Runtime: 4 ms, faster than 95.69% of C++ online submissions.
 * Memory usage: 7.9 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool LengthComp(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

std::string longestCommonPrefix(std::vector<std::string> &strs) {  
  if (strs.empty()) return "";

  std::string lcp;
  int i = 0;
 
  // Optional sort ensures we terminate as early as possible.
  std::sort(strs.begin(), strs.end(), LengthComp);

  bool proceed = true;
  while (proceed) {
    for (const std::string &s : strs) {
      if (s.size() == i || s[i] != strs[0][i]) {
        proceed = false;
        break;
      }
    }
    if (proceed) lcp += strs[0][i++];
  }
  
  return lcp;
}

int main() {
  std::vector<std::string> v1 = {"flower", "flow", "flight"};
  for (std::string &s : v1) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longestCommonPrefix(v1) << "\"\n\n";

  std::vector<std::string> v2;
  for (std::string &s : v2) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longestCommonPrefix(v2) << "\"\n\n";
  
  std::vector<std::string> v3 = {"dog", "", "dingo"};
  for (std::string &s : v3) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longestCommonPrefix(v3) << "\"\n\n";
  
  std::vector<std::string> v4 = {"dog", "cat", "rat"};
  for (std::string &s : v4) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longestCommonPrefix(v4) << "\"\n\n";
  
  std::vector<std::string> v5 = {"dog"};
  for (std::string &s : v5) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longestCommonPrefix(v5) << "\"\n\n";
}
