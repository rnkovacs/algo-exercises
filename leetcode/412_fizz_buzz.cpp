/* Write a program that outputs the string representation of numbers from 1 to n.
 *
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 *
 * Runtime: 4 ms, faster than 96.34% of C++ online submissions.
 * Memory usage: 9.4 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::vector<std::string> fizzBuzz(int n) {
  std::vector<std::string> v;

  for (int i = 1; i <= n; ++i) {
    std::string s;
    if (i % 3 == 0) s += "Fizz";
    if (i % 5 == 0) s += "Buzz";
    if (s.empty()) s = std::to_string(i);
    v.push_back(s);
  }
  
  return v;
}

int main() {
  std::vector<std::string> v = fizzBuzz(15);
  for (const std::string &s: v)
    std::cout << s << ' ';
  std::cout << '\n';
}
