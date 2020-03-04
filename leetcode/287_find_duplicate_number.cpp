/* Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Runtime: 4 ms, faster than 99.89% of C++ online submissions.
 * Memory usage: 9.9 MB, less than 90.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int findDuplicate(std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[slow];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    int p1 = 0;
    int p2 = slow;
    while (p1 != p2) {
        p1 = nums[p1];
        p2 = nums[p2];
    }
    return p1;
}

int main() {
  std::vector<int> nums {1,3,4,2,2};
  for (int i: nums) std::cout << i << ' ';
  std::cout << "\nDuplicate: " << findDuplicate(nums) << '\n';
}
