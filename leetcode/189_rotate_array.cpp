/* Given an array, rotate it to the right by k steps, where k is non-negative.
 *
 * Runtime: 12 ms, faster than 99.58% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

void rotate(std::vector<int> &nums, int k) {
    //  1  2  3  4  5  6  7  and k = 3, n == 7
    // 7 6 5 | 4 3 2 1
    // 5 6 7 | 1 2 3 4
    int n = nums.size();
    k = k % n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
  std::vector<int> nums {1,2,3,4,5,6,7};
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
  rotate(nums, 3);
  std::cout << "rotated by 3:\n";
  for (int i: nums) std::cout << i << ' '; std::cout << '\n'; 
}
