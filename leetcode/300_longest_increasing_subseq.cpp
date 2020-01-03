/* Given an unsorted array of integers, find the length of the longest
 * increasing subsequence.
 *
 * Runtime: 40 ms, faster than 49.37% of C++ online submissions.
 * Memory usage: 8.7 MB, less than 54.69% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int lengthOfLIS(std::vector<int>& nums) {
  int N = nums.size();
  if (N < 2) return N;
  
  std::vector<int> lengths(N);
  lengths[0] = 1;
  
  int globalMax = 1;
  for (int i=1; i<N; i++) {
    int localMax = 0;
    for (int j=0; j<i; j++) {
      if (nums[i] > nums[j]) {
        localMax = std::max(localMax, lengths[j]);
      }
    }
    lengths[i] = localMax + 1;
    globalMax = std::max(globalMax, lengths[i]);
  }
  
  return globalMax;
}

int main() {
  std::vector<int> v {10,9,2,5,3,7,101,18};
  for (int i: v) std::cout << i << ' ';
  std::cout << "\n" << lengthOfLIS(v) << '\n';
}
