/* Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 *
 * Runtime: 8 ms, faster than 94.97% of C++ online submissions.
 * Memory usage: 8.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool checkInclusion(std::string s1, std::string s2) {
  int windowEnd = s1.size();
  int strEnd = s2.size();
  
  if (windowEnd > strEnd) return false;

  std::vector<int> count(26, 0);
  for (char c: s1) ++count[c - 'a'];
  
  std::vector<int> empty(26, 0);
  
  // Do first whole window.
  for (int j = 0; j < windowEnd; ++j)
      --count[s2[j] - 'a'];
  if (count == empty) return true;
  
  // Do rest of the string incrementally.
  for (int remove = 0, add = windowEnd; add < strEnd; ++add, ++remove) {
    ++count[s2[remove] - 'a'];
    --count[s2[add] - 'a'];
    if (count == empty) return true;
  }
  
  return false;
}

int main() {
  std::cout << "ab eidbaooo\n" << checkInclusion("ab", "eidbaooo") << '\n';
  std::cout << "ab eidboaoo\n" << checkInclusion("ab", "eidboaoo") << '\n';
}
