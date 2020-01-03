/* Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 * In one operation, you can choose any character of the string and change it
 * to any other uppercase English character.
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 *
 * Runtime: 16 ms, faster than 57.57% of C++ online submissions.
 * Memory usage: 9.4 MB, less than 55.17% of C++ online submissions.
 */

#include <iostream>
#include <set>

int characterReplacement(std::string s, int k) {
  if (s.empty()) return 0;

  // Collect all distinct characters in the string.
  std::set<char> pool;
  for (char c: s) {
    if (!pool.count(c)) pool.insert(c);
  }

  int maxLen = 0;
  for (char c: pool) {
    int count = k;
    int l = -1;
    for (int r=0, len=s.size(); r<len; ++r) {
      // If the current char is not c, use one change-spot from k.
      if (s[r] != c) count--;
      
      // If we used up all change-spots, increment the left pointer.
      // Gain a change-spot back if we see a different char from c.
      while (count < 0 && l < r) {
        if (s[++l] != c) count++;
      }
      
      // If this is a valid state, update maxLen.
      if (count >= 0)
        maxLen = std::max(maxLen, r - l);
    }
  }

  return maxLen;
}

int main() {
  std::cout << "ABAB 2 " << characterReplacement("ABAB", 2) << '\n';
  std::cout << "AABABBA 1 " << characterReplacement("AABABBA", 1) << '\n';
}
