/* Given a non-empty array of digits representing a non-negative integer,
 * plus one to the integer. The digits are stored such that the most
 * significant digit is at the head of the list, and each element in the
 * array contain a single digit. You may assume the integer does not
 * contain any leading zero, except the number 0 itself.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void plusOne(std::vector<int>& digits) {
  if (digits.empty())
    return;
  if (digits[0] == 0) {
    ++digits[0];
    return;
  }
  
  int N = digits.size();
  
  // last digit is not 9 - increment and return
  if (digits[N-1] < 9) {
    ++digits[N-1];
    return;
  }

  bool carry = false;
  for (int i = N - 1; i >= 0; --i) {
    if (digits[i] == 9) {
      carry = true;
      digits[i] = 0;
    } else {
      if (!carry) break;
      ++digits[i];
      carry = false;
      break;
    }
  }
  
  // all digits were 9s
  if (carry) digits.insert(digits.begin(), 1);
}

int main() {
  std::vector<int> num { 2, 9, 3, 9 };
  for (int i: num) std::cout << i << ' '; std::cout << '\n';
  plusOne(num);
  for (int i: num) std::cout << i << ' '; std::cout << '\n';
  
  std::vector<int> num2 { 9, 9, 9 };
  for (int i: num2) std::cout << i << ' '; std::cout << '\n';
  plusOne(num2);
  for (int i: num2) std::cout << i << ' '; std::cout << '\n';
}
