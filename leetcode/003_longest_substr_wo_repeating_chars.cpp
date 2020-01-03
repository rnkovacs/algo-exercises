/* Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Runtime: 24 ms, faster than 50.50% of C++ online submissions.
 * Memory usage: 13.3 MB, less than 33.83% of C++ online submissions.
 */

#include <unordered_set>
#include <iostream>

int lengthOfLongestSubstring(std::string str) {
  int len = str.size();
  if (len < 2) return len;
  
  std::unordered_set<char> window;
  int maxLen = 0;
  int l = 0;
  int r = 0;
  
  while (l < len && r < len) {
    if (!window.count(str[r])) {
      window.insert(str[r++]);
      maxLen = std::max(maxLen, r - l);
    } else {
      window.erase(str[l++]);
    }
  }
  
  return maxLen;
}

int main() {
  std::cout << "abcabcbb " << lengthOfLongestSubstring("abcabcbb") << '\n';
  std::cout << "bbbbb " << lengthOfLongestSubstring("bbbbb") << '\n';
  std::cout << "pwwkew " << lengthOfLongestSubstring("pwwkew") << '\n';
}
