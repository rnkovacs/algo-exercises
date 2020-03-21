/* Given an array A of integers, return true if and only if it is a valid
 * mountain array. A is a mountain array if and only if:
 *
 * - A.length >= 3
 * - There exists some i with 0 < i < A.length - 1 such that:
 *   - A[0] < A[1] < ... A[i-1] < A[i]
 *   - A[i] > A[i+1] > ... > A[A.length - 1]
 *
 * Runtime:
 * Memory usage:
 */

#include <iostream>
#include <vector>

bool validMountainArray(std::vector<int> &A) {
  int N = A.size();
  if (N < 3) return false;
  
  int inc = 0;
  while (inc < N-1 && A[inc] < A[inc + 1]) ++inc;
  if (inc == 0) return false;
  if (inc >= N - 1) return false;
  
  for (int i = inc; i < N - 1; ++i) {
    if (A[i] <= A[i + 1]) return false;
  }
  
  return true;
}

int main() {
  std::vector<int> nums {2,1};
  for (int i: nums) std::cout << i << ' ';
  std::cout << "\n" << validMountainArray(nums) << '\n';
  
  std::vector<int> nums2 {0,3,2,1};
  for (int i: nums2) std::cout << i << ' ';
  std::cout << "\n" << validMountainArray(nums2) << '\n';
}
