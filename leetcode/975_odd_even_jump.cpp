/* You are given an integer array A.  From some starting index, you can make
 * a series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called
 * odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are
 * called even numbered jumps. You may from index i jump forward to index j
 * (with i < j) in the following way:
 *
 * - During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index
 *   j such that A[i] <= A[j] and A[j] is the smallest possible value.
 *   If there are multiple such indexes j, you can only jump to the smallest
 *   such index j.
 * - During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index
 *   j such that A[i] >= A[j] and A[j] is the largest possible value.
 *   If there are multiple such indexes j, you can only jump to the smallest
 *   such index j.
 * - (It may be the case that for some index i, there are no legal jumps.)
 *
 * A starting index is good if, starting from that index, you can reach the
 * end of the array (index A.length - 1) by jumping some number of times
 * (possibly 0 or more than once.)
 *
 * Return the number of good starting indexes.
 *
 * Runtime: 100 ms, faster than 64.92% of C++ online submissions.
 * Memory usage: 18 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int oddEvenJumps(std::vector<int> &A) {
  int N = A.size();

  std::set<std::pair<int, int>> valIdx;
  valIdx.insert({ A[N - 1], N - 1 });
  
  std::vector<bool> odd(N, false);
  std::vector<bool> even(N, false);
  odd[N - 1] = true;
  even[N - 1] = true;
        
  for (int i = N - 2; i >= 0; --i) {
    auto closestGE = valIdx.lower_bound({ A[i], -1 });
    if (closestGE != valIdx.end())
      odd[i] = even[closestGE->second];
    // else odd[i] remains false
    
    auto closestSE = closestGE;
    if (closestSE == valIdx.end()) --closestSE;
    else if (closestSE->first != A[i]) {
      if (closestSE == valIdx.begin()) {
        valIdx.insert({ A[i], i });
        continue; // even[i] remains false
      }
      --closestSE;
    }
    
    // if there are equal values, find the first one
    while (closestSE != valIdx.begin() &&
           (--closestSE)->first == (++closestSE)->first) {
      --closestSE;
    }
    
    even[i] = odd[closestSE->second];
    valIdx.insert({ A[i], i });
  }
  
  return std::count(odd.begin(), odd.end(), true);
}

int main() {
  std::vector<int> nums {2,3,1,1,4};
  std::cout << oddEvenJumps(nums) << '\n';
}
