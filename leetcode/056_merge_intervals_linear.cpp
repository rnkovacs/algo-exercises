/* Given a collection of intervals, merge all overlapping intervals.
 *
 * Runtime: 16 ms, faster than 94.22% of C++ online submissions.
 * Memory usage: 12.3 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool comp(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] < b[0];
}

std::vector<std::vector<int>>
merge(std::vector<std::vector<int>>& intervals) {
  int N = intervals.size();
  if (N < 2) return intervals;

  std::sort(intervals.begin(), intervals.end(), comp);
  
  std::vector<std::vector<int>> ints;
  ints.push_back(intervals[0]);
  
  for (int i=1; i<N; i++) {
    int maxIdx = ints.size() - 1;
    if (intervals[i][0] <= ints[maxIdx][1]) {
      // overlap with last merged int
      ints[maxIdx][1] = std::max(intervals[i][1], ints[maxIdx][1]);
    } else {
      ints.push_back(intervals[i]);
    }
  }

  return ints;
}

int main() {
  std::vector<std::vector<int>> ints { {1,3}, {2,6}, {8,10}, {15,18} };
  for (auto v: ints) std::cout << "(" << v[0] << "," << v[1] << ") ";
  std::cout << '\n';
  std::vector<std::vector<int>> ints2 = merge(ints);
  for (auto v: ints2) std::cout << "(" << v[0] << "," << v[1] << ") ";
  std::cout << '\n';
}
