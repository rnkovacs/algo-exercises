/*
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

class RandInRect {
  std::vector<std::vector<int>> &rects;
  std::vector<int> numPoints;
  std::random_device rd;
  std::mt19937 gen;
    
public:
  RandInRect(std::vector<std::vector<int>> &rects): rects(rects), gen(rd()) {
    // +--+--+--+--+    4
    // +  +  +  +  +
    // +--+--+--+--+    2
    // 1           5
    // (4 + 1) * (2 + 1) = 15
    
    for (int i = 0; i < rects.size(); ++i) {
        int dx = rects[i][2] - rects[i][0];
        int dy = rects[i][3] - rects[i][1];
        numPoints.push_back((dx + 1) * (dy + 1));
    }
    
    for (int i = 1; i < rects.size(); ++i)
        numPoints[i] += numPoints[i - 1];
  }
    
  std::vector<int> pick() {
      std::uniform_int_distribution<> dist(1, numPoints[numPoints.size() - 1]);
      int rand = dist(gen);

      auto it = std::lower_bound(numPoints.begin(), numPoints.end(), rand);
      assert(it != numPoints.end() && "Lower bound must exist in numPoints");
      
      int rect = std::distance(numPoints.begin(), it);
      int idx = rand - 1;
      if (rect > 0) idx -= numPoints[rect - 1];
      
      int ncols = rects[rect][2] - rects[rect][0] + 1;
      int x = rects[rect][0] + idx % ncols;
      int y = rects[rect][1] + idx / ncols;
      
      return { x, y };
  }
};

int main() {
  std::vector<std::vector<int>> rects { {-2,-2,-1,-1}, {1,0,3,0} };
  for (auto &v : rects) std::cout << v[0] << ' ' << v[1] << ' '
                                  << v[2] << ' ' << v[3] << '\n';
  std::cout << '\n';

  RandInRect r(rects);
  std::vector<int> p1 = r.pick();
  std::cout << p1[0] << ' ' << p1[1] << '\n';
  std::vector<int> p2 = r.pick();
  std::cout << p2[0] << ' ' << p2[1] << '\n';
  std::vector<int> p3 = r.pick();
  std::cout << p3[0] << ' ' << p3[1] << '\n';
}
