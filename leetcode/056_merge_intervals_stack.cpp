/* Given a collection of intervals, merge all overlapping intervals.
 *
 * Runtime: 12 ms, faster than 99.37% of C++ online submissions.
 * Memory usage: 13.3 MB, less than 34.88% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using Interval = std::pair<int, int>;
using IntervalList = std::vector<Interval>;

bool overlap(const Interval &a, const Interval &b) {
  const Interval &smaller = (a.first < b.first) ? a : b;
  const Interval &larger = (a.first > b.first) ? a : b;
  return larger.first <= smaller.second;
}
    
Interval getUnion(const Interval &a, const Interval &b) {
  return { std::min(a.first, b.first), std::max(a.second, b.second) };
}
    
IntervalList merge(const IntervalList &intervals, int l, int r) {
  if (l == r)
    return { intervals[l] };
    
  int m = (r - l) / 2 + l;
  IntervalList left = merge(intervals, l, m);
  IntervalList right = merge(intervals, m + 1, r);

  for (const Interval &interval : right) {
    Interval tmp = interval;
    for (auto it = left.begin(); it != left.end(); ) {
      if (overlap(*it, tmp)) {
        tmp = getUnion(*it, tmp);
        it = left.erase(it);
      } else {
        it++;
      }
    }
    left.push_back(tmp);
  }
        
  return left;
}
    
IntervalList merge(IntervalList& intervals) {
  int N = intervals.size();
  if (N < 2) return intervals;
    return merge(intervals, 0, N-1);
}

int main() {
	IntervalList list { {1,3}, {2,6}, {8,10}, {15,18} };
	for (const Interval &i : list)
		std::cout << "[" << i.first << ", " << i.second << "], ";
	std::cout << '\n';
	for (const Interval &i : merge(list))
		std::cout << "[" << i.first << ", " << i.second << "], ";
	std::cout << "\n\n";

 	IntervalList list2 { {1,2}, {3,4}, {5,6}, {1,10} };
	for (const Interval &i : list2)
		std::cout << "[" << i.first << ", " << i.second << "], ";
	std::cout << '\n';
	for (const Interval &i : merge(list2))
		std::cout << "[" << i.first << ", " << i.second << "], ";
	std::cout << '\n';
}
