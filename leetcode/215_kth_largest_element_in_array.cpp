/* Find the kth largest element in an unsorted array. Note that it is the
 * kth largest element in the sorted order, not the kth distinct element.
 *
 * Runtime: 72 ms, faster than 12.57% of C++ online submissions.
 * Memory usage: 7 MB, less than 100.00% of C++ online submissions.
 */

#include <vector>

int partition(std::vector<int> &nums, int lo, int hi) {
  if (lo == hi) return lo;
  
  int i = lo;
  int j = hi + 1;
  while (true) {
    while (nums[++i] < nums[lo]) { if (i == hi) break; }
    while (nums[--j] > nums[lo]) { if (j == lo) break; }
    if (i >= j) break;
    std::swap(nums[i], nums[j]);
  }
  
  std::swap(nums[j], nums[lo]);
  return j;
}

int findKthLargest(std::vector<int> &nums, int k) {
  int N = nums.size();
  if (N == 1) return nums[0];
  
  --k; // make it index
  
  int lo = 0;
  int hi = N - 1;
  
  while (lo <= hi) {
    int fromFront = partition(nums, lo, hi);
    int fromBack = N - 1 - fromFront;
    
    if (k == fromBack) return nums[fromFront];
    if (k < fromBack) lo = fromFront + 1;
    else              hi = fromFront - 1;
  }
  
  return -1;
}
