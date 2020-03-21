/* Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

int strStr(std::string haystack, std::string needle) {
  if (needle.empty()) return 0;
  int hSize = haystack.size();
  int nSize = needle.size();
  if (hSize < nSize) return -1;
  
  int startEnd = hSize - nSize + 1;
  int windowEnd = nSize;
  
  for (int start = 0; start < startEnd; ++start) {
    for (int i = 0; i < windowEnd; ++i) {
      if (haystack[start + i] != needle[i]) break;
      if (i == windowEnd - 1) return start;
    }
  }
  
  return -1;
}

int main() {
  std::cout << "hello ll\n" << strStr("hello", "ll") << '\n';
  std::cout << "aaaaa bba\n" << strStr("aaaaa", "bba") << '\n';
}
