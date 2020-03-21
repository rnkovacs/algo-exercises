/* Given an array of meeting time intervals consisting of start and end times,
 * find the minimum number of conference rooms required.
 *
 * Runtime: 16 ms, faster than 95.06% of C++ online submissions.
 * Memory usage: 11.3 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int minMeetingRooms(std::vector<std::vector<int>> &intervals) {
  int N = intervals.size();
  if (N < 2) return N;
      
  std::vector<int> starts;
  std::vector<int> ends;
  
  for (std::vector<int> &v : intervals) {
    starts.push_back(v[0]);
    ends.push_back(v[1]);
  }

  std::sort(starts.begin(), starts.end());
  std::sort(ends.begin(), ends.end());
  
  int rooms = 0;
  int maxRooms = 0;
  
  int i = 0;
  int j = 0;
    
  while (i < starts.size() && j < ends.size()) {
    if (starts[i] < ends[j]) {
      maxRooms = std::max(maxRooms, ++rooms);
      ++i;
    }
    else if (ends[j] < starts[i]) {
      if (rooms > 0) --rooms;
      ++j;
    } 
    else { // starts[i] == ends[j]
      ++i; ++j;
    }
  }

  return maxRooms;        
}

int main() {
  std::vector<std::vector<int>> i1 { {0,30}, {5,10}, {15,20} };
  for (auto v: i1) std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nMin # of conf rooms: " << minMeetingRooms(i1) << "\n\n";
  
  std::vector<std::vector<int>> i2 { {0,30}, {5,20}, {15,25} };
  for (auto v: i2) std::cout << "(" << v[0] << ", " << v[1] << ") ";
  std::cout << "\nMin # of conf rooms: " << minMeetingRooms(i2) << "\n";
}
