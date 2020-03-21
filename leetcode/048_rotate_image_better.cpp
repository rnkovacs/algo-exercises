/* You are given an nxn 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.9 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix) {
  int N = matrix.size();
  if (N <= 1) return;
  
  // Transpose.
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j)
      std::swap(matrix[i][j], matrix[j][i]);
    // Can also do the reverse here.
  }
  
  // Reverse rows.
  for (int i = 0; i < N; ++i)
    std::reverse(matrix[i].begin(), matrix[i].end());
}

int main() {
  std::vector<std::vector<int>> matrix { {1,2,3},
                                         {4,5,6},
                                         {7,8,9} };
  for (auto &v : matrix) {
    for (int i : v) std::cout << i << ' ';
    std::cout << '\n';
  }
  rotate(matrix);
  for (auto &v : matrix) {
    for (int i : v) std::cout << i << ' ';
    std::cout << '\n';
  }
}
