/* Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 *
 * Runtime: 0 ms (?), less than 100.00% of C++ online submissions.
 * Memory usage: 8.2 MB, less than 50.00% of C++ online submissions.
 */

#include <iostream>

unsigned getDigit(unsigned num, int idx) {
  return (num & (1 << idx)) >> idx;
}

unsigned getSumDigit(unsigned ad, unsigned bd, int &carry) {
  int digit = ad ^ bd;
  if (carry) digit = digit ? 0 : 1;
  carry = carry ? (ad | bd) : (ad & bd);
  return digit;
}

int getSum(int a, int b) {
  unsigned aa = a;
  unsigned bb = b;
  int sum = 0;
  int carry = 0;
  for (int i=0; i<32; i++) {
    unsigned ad = getDigit(aa, i);
    unsigned bd = getDigit(bb, i);
    unsigned sd = getSumDigit(ad, bd, carry);
    sum |= (sd << i);
  }
  return sum;
}

int main() {
  std::cout << "1 -3 " << getSum(1, -3) << '\n';
}
