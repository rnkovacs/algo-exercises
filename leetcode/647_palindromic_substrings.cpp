/* Given a string, count how many palindromic substrings there are in this
 * string.
 *
 * Runtime: 4 ms, faster than 90.46% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 80.00% of C++ online submissions.
 */

#include <iostream>

int countSubstrings(std::string s) {
  int N = s.size();
  if (N < 2) return N;
  
  int count = 0;
  for (int i=0; i<N; i++) {
    int l = i;
    int r = i;
    while (l >= 0 && r < N && s[l] == s[r]) {
      l--; r++; count++;
    }
    l = i;
    r = i+1;
    while (l >= 0 && r < N && s[l] == s[r]) {
      l--; r++; count++;
    }
  }
  
  return count;
}

int main() {
  std::cout << "abc : " << countSubstrings("abc") << '\n';
  std::cout << "aaa : " << countSubstrings("aaa") << '\n';
}
