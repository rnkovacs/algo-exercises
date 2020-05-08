/* Runtime: 1240 ms, faster than 10.39% of C++ online submissions.
 * Memory usage: 136.7 MB, less than 25.00% of C++ online submissions.
 */

#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

const int INT_MAX = std::numeric_limits<int>::max();

struct Hash {
  size_t operator()(const std::vector<int> &p) const {
    return 40001 * p[0] + p[1];
  }
};

int minAreaRect(std::vector<std::vector<int>> &points) {
  int minArea = INT_MAX;
  
  std::unordered_set<std::vector<int>, Hash> s;
  for (std::vector<int> &p : points) s.insert(p);
  
  for (int i = 0; i < points.size(); ++i) {
    int x1 = points[i][0];
    int y1 = points[i][1];
    
    for (int j = i + 1; j < points.size(); ++j) {
      int x2 = points[j][0];
      int y2 = points[j][1];
      
      if ((x1 > x2 && y1 > y2) || (x1 < x2 && y1 < y2)) {
        if (s.find({ x1, y2 }) != s.end() && s.find({ x2, y1 }) != s.end()) {
          int area = std::abs(x1 - x2) * std::abs(y1 - y2);
          minArea = std::min(minArea, area);
        }
      }
    }
  }
  
  return minArea == INT_MAX ? 0 : minArea;
}

int main() {
  std::vector<std::vector<int>> points { {1,1}, {1,3}, {3,1}, {3,3}, {2,2} };
  std::cout << minAreaRect(points) << '\n';
}
