/* There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)). You may assume nums1 and nums2 cannot be both empty.
 *
 * Runtime: 20 ms, faster than 68.10% of C++ online submissions.
 * Memory usage: 7.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int findDivision(const std::vector<int> &a, int N,
                 const std::vector<int> &b, int M) {
  int low = 0;
  int high = N;
  int half = (N + M + 1) / 2;
  
  while (low <= high) {
    int mid = low + (high - low) / 2;
    
    int aRight = mid;
    int bRight = half - aRight;
    
    if (aRight < high && a[aRight] < b[bRight - 1])
      low = mid + 1;
    else if (aRight > low && b[bRight] < a[aRight - 1])
      high = mid - 1;
    else
      return mid;
  }
  
  return -1;
}
        
double findMedianSortedArrays(std::vector<int> &a, std::vector<int> &b) {
  int N = a.size();
  int M = b.size();
  
  // Make sure a is the shorter one. 
  if (N > M) {
    std::swap(a, b);
    std::swap(N, M);
  }
  
  if (!N) return (b[M / 2] + b[M / 2 + M % 2 - 1]) / 2.0;
  
  int len = N + M;
  int half = (len + 1) / 2;
  
  int aRight = findDivision(a, N, b, M);
  int bRight = half - aRight;
  
  int largestInFirst;
  if (aRight > 0 && bRight > 0)
    largestInFirst = std::max(a[aRight - 1], b[bRight - 1]);
  else
    largestInFirst = (aRight > 0) ? a[aRight - 1] : b[bRight - 1];

  if (len % 2)
      return largestInFirst;
  
  int smallestInSecond;
  if (aRight < N && bRight < M)
    smallestInSecond = std::min(a[aRight], b[bRight]);
  else
    smallestInSecond = (aRight < N) ? a[aRight] : b[bRight];
  
  return (largestInFirst + smallestInSecond) / 2.0;
}
