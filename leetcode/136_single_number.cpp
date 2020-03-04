/* Given a non-empty array of integers, every element appears twice except
 * for one. Find that single one.
 *
 * Your algorithm should have a linear runtime complexity. Can you implement
 * it without using extra memory?
 *
 * Runtime: 8 ms, faster than 98.43% of C++ online submissions.
 * Memory usage: 9.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int zero = 0;
    for (int i : nums)
        zero ^= i;
    return zero;
}

int main() {
  std::vector<int> nums {4, 1, 2, 1, 2};
  for (int i: nums) std::cout << i << ' ';
  std::cout << '\n' << singleNumber(nums) << '\n';
}
