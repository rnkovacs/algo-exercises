/* You are given a license key represented as a string S which consists
 * only alphanumeric character and dashes. The string is separated into
 * N+1 groups by N dashes.
 *
 * Given a number K, we would want to reformat the strings such that each
 * group contains exactly K characters, except for the first group which
 * could be shorter than K, but still must contain at least one character.
 * Furthermore, there must be a dash inserted between two groups and all
 * lowercase letters should be converted to uppercase.
 *
 * Given a non-empty string S and a number K, format the string according
 * to the rules described above.
 *
 * Runtime: 12 ms, faster than 72.99% of C++ online submissions.
 * Memory usage: 10.5 MB, less than 82.76% of C++ online submissions.
 */

#include <iostream>

std::string licenseKeyFormatting(std::string S, int K) {
  std::string withoutDashes;
  for (char c: S) {
      if (c != '-') withoutDashes += std::toupper(c);
  }

  std::string res;
  int i = 0;
  
  int len = withoutDashes.size();
  int firstLen = len % K;
  
  for ( ; i < firstLen; ++i) res += withoutDashes[i];
  if (firstLen != 0) res += '-';
  
  while (i < len) {
      for (int j = 0; j < K; ++j) res += withoutDashes[i++];
      res += '-';
  }
  res = res.substr(0, res.size() - 1);
  
  return res;
}

int main() {
  std::cout << "5F3Z-2e-9-w, 4\n"
            << licenseKeyFormatting("5F3Z-2e-9-w", 4) << '\n';
  std::cout << "2-5g-3-J, 2\n"
            << licenseKeyFormatting("2-5g-3-J", 2) << '\n';
}
