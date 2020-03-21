/* Given a 32-bit signed integer, reverse the digits of the integer.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.4 MB, less than 46.67% of C++ online submissions.
 */

#include <cstdlib>
#include <iostream>
#include <limits>
#include <queue>

int reverse(int x) {
  if (std::abs(x) < 10) return x;
  if (x == std::numeric_limits<int>::min()) return 0;
  
  bool negative = false;
  if (x < 0) negative = true;
  x = std::abs(x);
  
  std::queue<int> digits;
  while (x > 0) {
    digits.push(x % 10);
    x /= 10;
  }
  
  int newX = 0;
  bool leading = true;

  while (!digits.empty()) {
    int digit = digits.front();
    digits.pop();

    if (digit == 0 && leading)
      continue;

    leading = false;
    if (newX > std::numeric_limits<int>::max() / 10) return 0;
    newX = 10 * newX + digit;
  }
  
  if (negative) newX = - newX;
  return newX;
}

int main() {
  std::cout << " " << 123 << " |  " << reverse(123) << '\n';
  std::cout << -123 << " | " << reverse(-123) << '\n';
  std::cout << " " << 120 << " |   " << reverse(120) << '\n';
}
