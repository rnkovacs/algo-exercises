/* Given a collection of intervals, find the minimum number of intervals
 * you need to remove to make the rest of the intervals non-overlapping.
 *
 * Runtime: 12 ms, faster than 95.37% of C++ online submissions.
 * Memory usage: 11.5 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool smallerStart(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] < b[0];
}

int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
  int N = intervals.size();
  if (N < 2) return 0;
  
  std::sort(intervals.begin(), intervals.end(), smallerStart);
  int toRemove = 0;
  int last = 0; 
  // ^ last interval that is either non-overlapping with the previous ones
  // or is the soonest-ending of an overlapping group
  
  for (int i=1; i<N; i++) {
    if (intervals[i][0] < intervals[last][1]) { // overlap
      toRemove++;
      // keep last the soonest-ending overlapping interval
      if (intervals[i][1] < intervals[last][1])
        last = i;
    } 
    else { // no overlap
      last = i;
    }
  }
  
  return toRemove;
}

int main() {
  std::vector<std::vector<int>> i1 { {1,2}, {2,3}, {3,4}, {1,3} };
  for (auto v: i1)
    std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nIntervals to remove: " << eraseOverlapIntervals(i1) << "\n\n";
  
  std::vector<std::vector<int>> i2 { {1,2}, {1,2}, {1,2} };
  for (auto v: i2)
    std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nIntervals to remove: " << eraseOverlapIntervals(i2) << '\n';
}
