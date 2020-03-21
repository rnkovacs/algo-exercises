/* Reverse a string given as an array of characters.
 * Modify the array in-place.
 *
 * Runtime: 40 ms, faster than 97.40% of C++ online submissions.
 * Memory usage: 15.2 MB, less than 80.49% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void reverse_string(std::vector<char> &s) {
  int l = 0;
  int r = s.size() - 1;
  while (l < r) std::swap(s[l++], s[r--]);
}

void print(std::vector<char> &str) {
  std::cout << "\"";
  for (char c : str) std::cout << c;
  std::cout << "\"\n";
}

int main() {
  std::vector<char> str1 {'h', 'e', 'l', 'l', 'o'};
  print(str1);
  reverse_string(str1);
  print(str1);
  
  std::vector<char> str2;
  print(str2);
  reverse_string(str2);
  print(str2);
  
  std::vector<char> str3 {'A', 'B'};
  print(str3);
  reverse_string(str3);
  print(str3);
  
  std::vector<char> str4 {'A', 'B', 'C'};
  print(str4);
  reverse_string(str4);
  print(str4);
}
