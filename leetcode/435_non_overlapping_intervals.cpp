/* Given a collection of intervals, find the minimum number of intervals
 * you need to remove to make the rest of the intervals non-overlapping.
 *
 * Runtime: 12 ms, faster than 95.37% of C++ online submissions.
 * Memory usage: 11.5 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool inc(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
  int N = intervals.size();
  if (N < 2) return 0;
  
  std::sort(intervals.begin(), intervals.end(), inc);
  // [[1,2],[2,3]]
  // -    ---  ---
  // ---   -     --
  
  int last = 0;
  int count = 0;
  
  for (int i = 1; i < N; ++i) {
    if (intervals[last][1] <= intervals[i][0]) {
      // No overlap.
      last = i;
    }
    else {
      // Overlap. Keep the earlier ending one.
      last = (intervals[last][1] < intervals[i][1]) ? last : i;
      ++count;
    }
  }
  
  return count;
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
