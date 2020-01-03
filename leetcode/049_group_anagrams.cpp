/* Given an array of strings, group anagrams together.
 *
 * Runtime: 52 ms, faster than 37.47% of C++ online submissions.
 * Memory usage: 21.3 MB, less than 25.37% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using StrList = std::vector<std::string>;

std::vector<StrList> groupAnagrams(StrList &strs) {
  if (strs.size() < 1) return {{}};

  std::unordered_map<std::string, std::vector<int>> m;

  for (int i=0, s=strs.size(); i<s; i++) {
    std::string sorted = strs[i];
    std::sort(sorted.begin(), sorted.end());
    if (!m.count(sorted)) m.insert({sorted, {i}});
    else m[sorted].push_back(i);
  }

  std::vector<StrList> v;
  for (auto pair : m) {
    StrList sv;
    for (int idx : pair.second) {
      sv.push_back(strs[idx]);
    }
    v.push_back(sv);
  }
  
  return v;
}

int main() {
  StrList strs1 = {"",""};
  auto v1 = groupAnagrams(strs1);
  for (auto i : v1) {
    for (std::string s : i) std::cout << "\"" << s << "\"";
    std::cout << '\n';
  }
  
  StrList strs2 = {"eat","tea","tan","ate","nat","bat"};
  auto v2 = groupAnagrams(strs2);
  for (auto i : v2) {
    for (std::string s : i) std::cout << "\"" << s << "\"";
    std::cout << '\n';
  }
}
