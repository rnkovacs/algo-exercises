/* Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand. Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Runtime: 4 ms, faster than 98.77% of C++ online submissions.
 * Memory usage: 6.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool findDifferent(const std::vector<int> &nums, int start, int mid) {
  for (int i = start; i < nums.size(); ++i) {
    if (nums[i] != nums[mid]) return true;
  }
  return false;
}

int findMin(std::vector<int> &nums) {
  int N = nums.size();
  if (N == 1) return nums[0];
  
  int first = nums[0];
  int last = nums[N - 1];
  if (last > first) return first; // not rotated
  
  // last <= first
  int l = 0;
  int r = N - 1;
  while (l < r) {
    int m = l + (r - l) / 2;

    if (nums[m] > first) l = m + 1;

    else if (nums[m] < first) r = m;

    else { // nums[m] == first
      if (last < first) l = m + 1;
      else { // last == first
        if (findDifferent(nums, m + 1, m)) l = m + 1;
        else                               r = m;
      }
    }

    if (l == r) return nums[l];
  }
  
  return -1;
}

int main() {
  std::vector<int> nums {2,2,2,0,1};
  for (int i: nums) std::cout << i << ' ';
  std::cout << '\n' << findMin(nums) << '\n';
}
