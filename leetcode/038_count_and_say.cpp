/* The count-and-say sequence is the sequence of integers with the first
 * five terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence. You can do so recursively, in other words from
 * the previous member read off the digits, counting the number of digits
 * in groups of the same digit.
 *
 * Each term of the sequence of integers will be represented as a string.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

std::string countAndSay(int n, std::string str, int i) {
  if (i == n) return str;
  
  int N = str.size();
  if (N == 1) return countAndSay(n, "1" + str, i + 1);
  
  std::string newStr;
  int count = 1;

  for (int i = 1; i < N; ++i) {
    if (str[i] == str[i - 1]) {
      ++count;
      continue;
    }
    newStr += '0' + count;
    newStr += str[i - 1];
    count = 1;
  }
  newStr += '0' + count;
  newStr += str[N - 1];
  
  return countAndSay(n, newStr, i + 1);
}

std::string countAndSay(int n) {
  return countAndSay(n, "1", 1);
}

int main() {
  std::cout << "1 : " << countAndSay(1) << '\n';
  std::cout << "4 : " << countAndSay(4) << '\n';
}
