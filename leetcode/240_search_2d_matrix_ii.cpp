/* Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * - Integers in each row are sorted in ascending from left to right.
 * - Integers in each column are sorted in ascending from top to bottom.
 *
 * Runtime: 484 ms, faster than 9.32% of C++ online submissions.
 * Memory usage: 10.9 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target,
                  int r1, int r2, int c1, int c2) {    
  if (r1 > r2 || c1 > c2)
      return false;
  
  if (target < matrix[r1][c1] || target > matrix[r2][c2])
      return false;

  int midRow = r1 + (r2 - r1) / 2;
  auto midColIt = std::lower_bound(matrix[midRow].begin(),
                                   matrix[midRow].end(), target);
  int midCol = std::distance(matrix[midRow].begin(), midColIt);
  if (midCol < matrix[0].size() && matrix[midRow][midCol] == target)
      return true;
  
  return searchMatrix(matrix, target, midRow+1, r2, c1, midCol-1)
      || searchMatrix(matrix, target, r1, midRow-1, midCol, c2);
}

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int N = matrix.size();
  if (!N) return false;
  int M = matrix[0].size();
  if (!M) return false;
  return searchMatrix(matrix, target, 0, N-1, 0, M-1);
}

int main() {
  std::vector<std::vector<int>> m { { 1, 4, 7,11,15},
                                    { 2, 5, 8,12,19},
                                    { 3, 6, 9,16,22},
                                    {10,13,14,17,24},
                                    {18,21,23,26,30} };
  for (auto &v: m) {
    for (int i: v) std::cout << i << ' ';
    std::cout << '\n';
  }
  std::cout << "5 in matrix: " << searchMatrix(m, 5) << '\n';
  std::cout << "20 in matrix: " << searchMatrix(m, 20) << '\n';
}
