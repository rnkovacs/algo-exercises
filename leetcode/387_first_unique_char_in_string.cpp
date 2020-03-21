/* Given a string, find the first non-repeating character in it and return its
 * index. If it doesn't exist, return -1.
 *
 * Runtime: 36 ms, faster than 91.93% of C++ online submissions.
 * Memory usage: 12.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int firstUniqChar(std::string s) {
  std::vector<int> count(26, 0);
  for (char c: s)
    ++count[c - 'a'];
  
  for (int i=0, N=s.size(); i<N; ++i) {
    if (count[s[i] - 'a'] == 1)
      return i;
  }
  return -1;
}

int main() {
  std::cout << "first unique char in loveleetcode: "
            << firstUniqChar("loveleetcode") << '\n';
}
