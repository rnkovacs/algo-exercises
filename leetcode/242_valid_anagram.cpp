/* Given two strings s and t, write a function to determine if t is an
 * anagram of s.
 *
 * Runtime: 12 ms, faster than 82.03% of C++ online submissions.
 * Memory usage: 9.6 MB, less than 58.21% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool isAnagram(std::string s, std::string t) {
  std::vector<int> counts (26, 0);
  for (char c: s) counts[c - 'a']++;
  for (char c: t) counts[c - 'a']--;
  for (int i: counts) { if (i != 0) return false; }
  return true;
}

int main() {
  std::cout << "anagram nagaram " << isAnagram("anagram", "nagaram") << '\n';
  std::cout << "rat car " << isAnagram("rat", "car") << '\n';
}
