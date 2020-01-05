/* Given an array of meeting time intervals consisting of start and end times,
 * determine if a person could attend all meetings.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool laterStart(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] < b[0];
}

bool canAttendAll(std::vector<std::vector<int>> &intervals) {
  int N = intervals.size();
  if (N < 2) return true;

  std::sort(intervals.begin(), intervals.end(), laterStart);

  for (int i=1; i<N; i++) {
    if (intervals[i][0] > intervals[i-1][1])
      return false;
  }

  return true;
}

int main() {
  std::vector<std::vector<int>> i1 { {0,30}, {5,10}, {15,20} };
  for (auto v: i1) std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nCan attend all meetings: " << canAttendAll(i1) << "\n\n";
  
  std::vector<std::vector<int>> i2 { {0,30}, {5,20}, {15,25} };
  for (auto v: i2) std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nCan attend all meetings: " << canAttendAll(i2) << "\n";
}
