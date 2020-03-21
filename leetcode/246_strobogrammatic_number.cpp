/* A strobogrammatic number is a number that looks the same when rotated 
 * 180 degrees (looked at upside down).
 *
 * Write a function to determine if a number is strobogrammatic.
 * The number is represented as a string.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

bool arePairs(char c1, char c2) {
  return (c1 == '6' && c2 == '9') ||
         (c1 == '9' && c2 == '6') ||
         (c1 == '8' && c2 == '8') ||
         (c1 == '1' && c2 == '1') ||
         (c1 == '0' && c2 == '0');
}

bool isStrobogrammatic(std::string num) {
  // "69" -- 6 at 0 + 9 at N-1
  // "88" -- 8 at 0 + 8 at N-1
  int N = num.size();
  // "689"
  // "619"
  if (N % 2 && !arePairs(num[N/2], num[N/2]))
    return false;
  for (int i = 0; i < N/2; ++i) {
    if (!arePairs(num[i], num[N-1-i]))
        return false;
  }
  return true;
}

int main() {
  std::cout << "69: " << isStrobogrammatic("69") << '\n';
  std::cout << "962: " << isStrobogrammatic("962") << '\n';
}
