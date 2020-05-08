/* Given an input string (s) and a pattern (p), implement wildcard
 * pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 *
 * Runtime: 4 ms, faster than 98.83% of C++ online submissions.
 * Memory usage: 6.7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

bool isMatch(std::string s, std::string p) {
  int N = s.size();
  int M = p.size();
  
  int i = 0;
  int j = 0;
  int starPos = -1;
  int strPos = -1;

  while (i < N) {
    if (j < M && (s[i] == p[j] || p[j] == '?')) {
      ++i;
      ++j;
    }
    else if (j < M && p[j] == '*') {
      // Don't match it first: i, ++j.
      starPos = j;
      strPos = i;
      ++j;
    }
    // Not equal, no ?, and no *.
    // Did we get here from a *?
    else if (starPos == -1) {
      // If no, well bye.
      // This can also happen if we run out of pattern.
      return false;
    }
    else {
      // If yes, we can backtrack.
      j = starPos + 1;
      i = strPos + 1;
      strPos = i;
    }
  }
  
  // Now it's either 
  // (1) no more input + some pattern left, or
  // (2) both are out.
  // (1) is OK as long as it is all *s. (2) is always OK.

  while (j < M)
      if (p[j++] != '*') return false;
  
  return true;
}


