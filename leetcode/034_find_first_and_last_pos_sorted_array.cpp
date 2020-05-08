/* Given an array of integers nums sorted in ascending order, find the
 * starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 *
 * Runtime: 8 ms, faster than 82.35% of C++ online submissions.
 * Memory usage: 8.1 MB, less than 100.00% of C++ online submissions.
 */

int search(const std::vector<int> &nums, int l, int r, int target, bool lower) {
  while (l < r) {
    int m = (lower) ? (l + (r - l) / 2)
                    : (l + (r - l + 1) / 2);
    
    if (nums[m] == target) {
      if (lower) r = m;
      else       l = m;
    }
    else if (nums[m] < target)  l = m + 1;
    else /*(nums[m] > target)*/ r = m - 1;
    
    if (l == r && nums[l] == target) return l;
  }
  
  return -1;
}
    
std::vector<int> searchRange(std::vector<int> &nums, int target) {
  if (nums.empty()) return { -1, -1 };
  if (nums.size() == 1) {
      if (nums[0] == target) return { 0, 0 };
      return { -1, -1 };
  }
  
  int from = search(nums, 0, nums.size() - 1, target, true);
  int to = search(nums, 0, nums.size() - 1, target, false);
  
  return { from, to };
}
