/* Given an array of meeting time intervals consisting of start and end times,
 * find the minimum number of conference rooms required.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

bool laterStart(const std::vector<int> &a, const std::vector<int> &b) {
  return a[0] < b[0];
}

int minNumRooms(std::vector<std::vector<int>> &intervals) {
  int N = intervals.size();
  if (N < 2) return N;

  std::sort(intervals.begin(), intervals.end(), laterStart);

  int minRooms = 1;
  int rooms = 1;

  auto comp = [](std::vector<int> &a, std::vector<int> &b)
              { return a[1] > b[1]; };
  std::priority_queue<std::vector<int>, 
                      std::vector<std::vector<int>>,
                      decltype(comp)> q(comp);
  q.push(intervals[0]);

  for (int i=1; i<N; i++) {
    while (!q.empty()) {
      std::vector<int> endingEarliest = q.top();
      if (endingEarliest[1] > intervals[i][0])
        break;
      q.pop();
      rooms--;
    }

    q.push(intervals[i]);
    rooms++;

    if (rooms > minRooms) minRooms = rooms;
  }

  return minRooms;
}

int main() {
  std::vector<std::vector<int>> i1 { {0,30}, {5,10}, {15,20} };
  for (auto v: i1) std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nMin # of conf rooms: " << minNumRooms(i1) << "\n\n";
  
  std::vector<std::vector<int>> i2 { {0,30}, {5,20}, {15,25} };
  for (auto v: i2) std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nMin # of conf rooms: " << minNumRooms(i2) << "\n";
}
