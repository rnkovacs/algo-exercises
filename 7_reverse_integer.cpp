/* Given a 32-bit signed integer, reverse its digits.
 * Assume we are dealing with an environment which only stores integers within
 * the 32-bit signed integer range: [- 2-to-31, 2-to-31 - 1]. Your function
 * should return a 0 when the reversed integer overflows.
 *
 * Example: -123 -> -321
 *
 * Runtime: 4 ms, faster than 69.00% of C++ online submissions.
 * Memory usage: 8.1 MB, less than 100.00% (?) of C++ online submissions.
 */

#include <iostream>

int reverse(int x) {
  int max_neg = -2147483648;
  int max_pos = 2147483647;

  if (x == max_neg)
    return 0;

  int sign = (x >= 0) ? 1 : -1;
  if (sign < 0) x = -x;

  int n = 1;
  int xcopy = x / 10;
  while (xcopy > 0) {
    n *= 10;
    xcopy /= 10;
  }

  int new_x = 0;
  while (x > 0) {
    int digit = x % 10;
    x /= 10;

    // digit * n itself would overflow
    if (n == 1000000000 && digit > 2)
      return 0;

    // will new_x overflow at any point?
    int to_add = digit * n;
    if (new_x > max_pos - to_add)
      return 0;

    new_x += to_add;
    n /= 10;
  }

  return new_x * sign;
}

int main() {
  int i = -123;
  std::cout << i << '\n' << reverse(i) << "\n\n";

  i = -2147483648;
  std::cout << i << '\n' << reverse(i) << "\n\n";

  i = 2147483647;
  std::cout << i << '\n' << reverse(i) << "\n\n";

  i = 2147417412;
  std::cout << i << '\n' << reverse(i) << "\n\n";
  
  i = -2147417412;
  std::cout << i << '\n' << reverse(i) << "\n\n";
}
