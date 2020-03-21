/* Median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value. So the median is the mean
 * of the two middle value.
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the
 * k numbers in the window. Each time the sliding window moves right by one
 * position. Your job is to output the median array for each window in the
 * original array.
 *
 * Runtime: 60 ms, faster than 94.36% of C++ online submissions.
 * Memory usage: 14.4 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <set>
#include <vector>

std::vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {       
  std::vector<double> medians;
  
  std::multiset<int> ordered(nums.begin(), nums.begin() + k);
  auto middle = std::next(ordered.begin(), k / 2);
  
  medians.push_back(*middle / 2.0 + *std::next(middle, k % 2 - 1) / 2.0);

  for (int i = k; i < nums.size(); ++i) {
    ordered.insert(nums[i]);
    if (nums[i] < *middle) --middle;
    // if k is odd, it is now on the first middle element
    
    if (nums[i - k] <= *middle) ++middle;
    ordered.erase(ordered.lower_bound(nums[i - k]));
    
    medians.push_back(*middle / 2.0 + *std::next(middle, k % 2 - 1) / 2.0);
  }
  
  return medians;
}

int main() {
  std::vector<int> nums {1,3,-1,-3,5,3,6,7};
  for (int i: nums) std::cout << i << ' ';
  std::cout << '\n';
  for (double d: medianSlidingWindow(nums, 3)) std::cout << d << ' ';
  std::cout << '\n';
}
