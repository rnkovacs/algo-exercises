/* Given n non-negative integers a1, a2, ..., an, where each represents a
 * point at coordinate (i, ai), n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
 * together with x-axis forms a container, such that the container contains
 * the most water.
 *
 * Runtime: 20 ms, faster than 66.79% of C++ online submissions.
 * Memory usage: 9.8 MB, less than 68.04% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height) {
  int max_area = 0;   
  int l = 0;
  int r = height.size() - 1;
  
  while (l < r) {
    int area = std::min(height[l], height[r]) * (r - l);
    if (area > max_area) max_area = area;
    if (height[l] < height[r]) l++;
    else r--;
  }

  return max_area;
}

int main() {
  std::vector<int> v {1,8,6,2,5,4,8,3,7};
  std::cout << maxArea(v) << '\n';
}
