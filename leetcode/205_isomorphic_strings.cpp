/* Given two strings s and t, determine if they are isomorphic. Two strings
 * are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character
 * while preserving the order of characters. No two characters may map to the
 * same character but a character may map to itself.
 *
 * Runtime: 12 ms, faster than 53.86% of C++ online submissions.
 * Memory usage: 7.1 MB, less than 100.00% of C++ online submission.
 */

#include <unordered_map>
#include <unordered_set>

bool isIsomorphic(std::string s, std::string t) {
  std::unordered_map<char, char> map;
  std::unordered_set<char> taken;
  
  for (int i = 0; i < s.size(); ++i) {
    if (map.find(s[i]) != map.end()) {
      if (map[s[i]] != t[i])
        return false;
    } else {
      if (taken.find(t[i]) != taken.end())
        return false;
      map.insert({ s[i], t[i] });
      taken.insert( t[i] );
    }
  }
  
  return true;
}
