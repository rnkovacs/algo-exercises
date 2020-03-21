/* A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are
 * the coordinates of its bottom-left corner, and (x2, y2) are the coordinates
 * of its top-right corner.
 *
 * Two rectangles overlap if the area of their intersection is positive.
 * Two rectangles that only touch at the corner or edges do not overlap.
 *
 * Given two (axis-aligned) rectangles, return whether they overlap.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool intervalOverlap(const std::vector<int> &a, const std::vector<int> &b) {
  const auto &first = (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1])) ? a : b;
  const auto &second = (first == b) ? a : b;
  return first[1] > second[0];
}
    
bool isRectangleOverlap(std::vector<int> &rec1, std::vector<int> &rec2) {
  // [x1, y1, x2, y2]
  //  bleft   tright
  
  //    +----+
  //  +-|--+ |
  //  +-+--+-+
  
  std::vector<int> r1x = { rec1[0], rec1[2] };
  std::vector<int> r1y = { rec1[1], rec1[3] };
  
  std::vector<int> r2x = { rec2[0], rec2[2] };
  std::vector<int> r2y = { rec2[1], rec2[3] };
  
  bool xOverlap = intervalOverlap(r1x, r2x);
  bool yOverlap = intervalOverlap(r1y, r2y);
  
  return xOverlap && yOverlap;
}

int main() {
  //      +-------+
  //  +---+---+   |
  //  |   +---+---+
  //  +-------+
  std::vector<int> rec1 {0,0,2,2};
  std::vector<int> rec2 {1,1,3,3};
  std::cout << isRectangleOverlap(rec1, rec2) << '\n';

  //  +---+---+
  //  |   |   |
  //  +---+---+
  std::vector<int> rec3 {0,0,1,1};
  std::vector<int> rec4 {1,0,2,1};
  std::cout << isRectangleOverlap(rec3, rec4) << '\n';
}
