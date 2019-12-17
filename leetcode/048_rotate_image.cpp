/* You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees clockwise.
 * Note: you have to rotate the image in-place.
 *
 * Runtime: 4 ms, faster than 83.43% of C++ online submissions.
 * Memory usage: 8.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix) {
  int N = matrix.size();
  if (N <= 1) return;
  
  int level = 0;
  while (level < N/2) {
    for (int i=level; i<(N-1-level); ++i) {
      int save = matrix[level][i];
      matrix[level][i] = matrix[N-1-i][level];
      matrix[N-1-i][level] = matrix[N-1-level][N-1-i];
      matrix[N-1-level][N-1-i] = matrix[i][N-1-level];
      matrix[i][N-1-level] = save;
    }
    level++;
  }
}

int main() {
  std::vector<std::vector<int>> m { {1,2,3}, {4,5,6}, {7,8,9} };
  for (auto v : m) {
    for (int i : v) std::cout << i << ' ';
    std::cout << '\n';
  }
  std::cout << "After rotate:\n";
  rotate(m);
  for (auto v : m) {
    for (int i : v) std::cout << i << ' ';
    std::cout << '\n';
  }
}
