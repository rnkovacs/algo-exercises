/* Given a set of non-overlapping intervals, insert a new interval into
 * the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to
 * their start times.
 *
 * Runtime: 16 ms, faster than 81.49% of C++ online submissions.
 * Memory usage: 12 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool inc(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] < b[0];
}

bool overlap(const std::vector<int> &a, const std::vector<int> &b) {
  // ---      ----
  //   ---   ---
  return    (a[0] <= b[0] && a[1] >= b[0])
         || (b[0] <= a[0] && b[1] >= a[0]);
}
    
std::vector<std::vector<int>>
insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
  if (intervals.empty()) return { newInterval };
  
  std::vector<std::vector<int>> res;
      
  int minVal = newInterval[0];
  int maxVal = newInterval[1];
  std::vector<int> indexes;
    
  for (int i = 0; i < intervals.size(); ++i) {
    if (overlap(intervals[i], newInterval)) {
      minVal = std::min(intervals[i][0], minVal);
      maxVal = std::max(intervals[i][1], maxVal);
      indexes.push_back(i);
    }
  }
  
  if (indexes.empty()) {
    res = intervals;
    res.push_back(newInterval);
    std::sort(res.begin(), res.end(), inc);
    return res;
  }
  
  for (int i = 0; i < indexes[0]; ++i)
    res.push_back(intervals[i]);
  
  res.push_back({ minVal, maxVal });
  
  for (int i = indexes[indexes.size() - 1] + 1; i < intervals.size(); ++i)
    res.push_back(intervals[i]);
  
  return res;
  // indexes of intervals we overlap with
  // merge: keep track of min and max values
  // replace old intervals with one merged interval
}
