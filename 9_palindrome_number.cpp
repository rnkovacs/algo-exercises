/*
 * Runtime: 20 ms, faster than 31.54% of C++ online submissions.
 * Memory usage: 7.9 MB, less than 100.00% (?) of C++ online submissions.
 */

#include <iostream>

bool is_palindrome(int x) {
  if (x == 0)
    return true;

  if (x < 0 || !(x % 10))
    return false;

  int l = 1;
  int xcopy = x / 10;
  while (xcopy > 0) {
    l *= 10;
    xcopy /= 10;
  }

  int r = 1;

  // avoid overflowing l for numbers around INT_MAX
  int left = x / l;
  int right = x % 10;

  if (left != right)
    return false;

  l /= 10;
  r *= 10;

  while (l > r) {
    left = (x % (l * 10)) / l;
    right = (x % (r * 10)) / r;

    if (left != right)
      return false;

    l /= 10;
    r *= 10;
  }

  return true;
}

int main() {
  int i = 121;
  std::cout << i << '\n' << is_palindrome(i) << "\n\n";

  i = -121;
  std::cout << i << '\n' << is_palindrome(i) << "\n\n";

  i = 0;
  std::cout << i << '\n' << is_palindrome(i) << "\n\n";
  
  i = 2147483647;
  std::cout << i << '\n' << is_palindrome(i) << "\n\n";

  i = 2147337412;
  std::cout << i << '\n' << is_palindrome(i) << "\n\n";
}
