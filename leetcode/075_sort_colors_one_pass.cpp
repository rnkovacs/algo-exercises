/* Given an array with n objects colored red, white or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors
 * in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 *
 * You are not suppose to use the library's sort function for this problem.
 *
 * Runtime: 4 ms, faster than 68.67% of C++ online submissions.
 * Memory usage: 6.4 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void sortColors(std::vector<int> &nums) {
  int N = nums.size();
  int pivot = 1;
  
  // [0,0,0,1,1,1,2,2]
  //        m
  //              u
  //              b
  
  int mid = 0;      // first mid
  int unseen = 0;   // first unseen
  int back = N;     // first back
  
  while (unseen < back) {
    if (nums[unseen] > pivot)
        std::swap(nums[unseen], nums[--back]);
    else if (nums[unseen] < pivot)
        std::swap(nums[unseen++], nums[mid++]);
    else // nums[unseen] == pivot
        ++unseen;
  }
}

int main() {
  std::vector<int> nums {2,0,2,1,1,0};
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
  sortColors(nums);
  for (int i: nums) std::cout << i << ' '; std::cout << '\n';
}
