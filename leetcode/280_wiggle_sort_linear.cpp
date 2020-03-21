/* Given an unsorted array nums, reorder it in-place such that
 * nums[0] <= nums[1] >= nums[2] <= nums[3]....
 *
 * Runtime: 28 ms, faster than 99.31% of C++ online submissions.
 * Memory usage: 9.2 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

void wiggleSort(std::vector<int> &nums) {
  int N = nums.size();
  if (N < 2) return;
   
  // 4 5 6 -> 4 6 5
  //  / /  ->  / \
  
  // 6 5 4 -> 6 4 5
  //  \ \  ->  \ /
  bool less = true;
  for (int i = 0; i < N - 1; ++i) {
    if (   (less && nums[i] > nums[i + 1])
        || (!less && nums[i] < nums[i + 1])) {
      std::swap(nums[i], nums[i + 1]);
    }
    less = !less;
  }       
}

int main() {
  std::vector<int> nums {3,5,2,1,6,4};
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
  wiggleSort(nums);
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
}
