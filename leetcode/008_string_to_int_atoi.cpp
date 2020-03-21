/* Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary
 * until the first non-whitespace character is found. Then, starting from
 * this character, takes an optional initial plus or minus sign followed by
 * as many numerical digits as possible, and interprets them as a numerical
 * value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * 1. Only the space character ' ' is considered as whitespace character.
 * 2. Assume we are dealing with an environment which could only store
 *    integers within the 32-bit signed integer range: [−231,  231 − 1].
 *    If the numerical value is out of the range of representable values,
 *    INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <limits>

const int INT_MAX = std::numeric_limits<int>::max();
const int INT_MIN = std::numeric_limits<int>::min();

int myAtoi(std::string str) {
  if (str.empty()) return 0;
  int N = str.size();
  
  // initial whitespace
  int i = 0;
  while (str[i] == ' ' && i < N) ++i;
  if (i == N) return 0;
  
  // optional sign
  int sign = 1;
  if (str[i] == '-') { sign = -1; ++i; }
  else if (str[i] == '+') ++i;
  if (i == N || !std::isdigit(str[i])) return 0;

  int num = 0;
  while (i < N && std::isdigit(str[i])) {
    int digit = str[i] - '0';
    if (num > INT_MAX / 10)
      return sign == 1 ? INT_MAX : INT_MIN;
    if (num == INT_MAX / 10) {
      if (sign == 1 && digit >= 7) return INT_MAX;
      if (sign == -1 && digit >= 8) return INT_MIN;
    }
    num = 10 * num + digit;
    ++i;
  }
  
  return sign * num;
}

int main() {
  std::cout << "\"42\" : " << myAtoi("42") << '\n';
  std::cout << "\"     -42\" : " << myAtoi("     -42") << '\n';
  std::cout << "\"4193 with words\" : " << myAtoi("4193 with words") << '\n';
  std::cout << "\"words and 987\" : " << myAtoi("words and 987") << '\n';
  std::cout << "\"-91283472332\" : " << myAtoi("-91283472332") << '\n';
}
