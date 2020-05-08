/* Given a string containing digits from 2-9 inclusive, return all
 * possible letter combinations that the number could represent.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 6.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::unordered_map<char, std::string> m =
  { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };

void collectLetters(const std::string &digits, int i, std::string s,
                    std::vector<std::string> &v) {
  if (i == digits.size()) {
    v.push_back(s);
    return;
  }
  
  for (char ch: m[digits[i]])
    collectLetters(digits, i + 1, s + ch, v);
}

std::vector<std::string> letterCombinations(std::string digits) {
  if (digits.empty()) return {};
  
  std::vector<std::string> v;
  collectLetters(digits, 0, "", v);
  return v;
}
