/*
 * Runtime: 4 ms, faster than 95.29% of C++ online submissions.
 * Memory usage: 8.7 MB, less than 93.55% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::string longest_common_prefix(std::vector<std::string>& strs) {
  if (strs.empty())
    return "";

  char c = 0;
  std::string prefix = "";
  int i = 0;

  while (true) {
    for (std::string &s : strs) {
      if (!s[i])
        return prefix;
      if (!c) {
        c = s[i];
        continue;
      }
      if (s[i] != c)
        return prefix;
    }
    prefix += c;
    c = 0;
    ++i;
  }

  return prefix;
}

int main() {
  std::vector<std::string> v1 = {"flower", "flow", "flight"};
  for (std::string &s : v1) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longest_common_prefix(v1) << "\"\n\n";

  std::vector<std::string> v2;
  for (std::string &s : v2) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longest_common_prefix(v2) << "\"\n\n";
  
  std::vector<std::string> v3 = {"dog", "", "dingo"};
  for (std::string &s : v3) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longest_common_prefix(v3) << "\"\n\n";
  
  std::vector<std::string> v4 = {"dog", "cat", "rat"};
  for (std::string &s : v4) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longest_common_prefix(v4) << "\"\n\n";
  
  std::vector<std::string> v5 = {"dog"};
  for (std::string &s : v5) std::cout << "\"" << s << "\" ";
  std::cout << "\nprefix: \"" << longest_common_prefix(v5) << "\"\n\n";
}
