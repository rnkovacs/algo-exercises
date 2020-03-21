/* Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * - Integers in each row are sorted from left to right.
 * - The first integer of each row is greater than the last integer of the
 *   previous row.
 *
 * Runtime: 8 ms, faster than 92.20% of C++ online submissions.
 * Memory usage: 7.8 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int nRows = matrix.size();
  if (!nRows) return false;
  int nCols = matrix[0].size();
  if (!nCols) return false;
  
  int row = 0;
  
  int first = 0;
  int last = nRows - 1;
  while (first < last) {
    int mid = first + (last - first) / 2;
    if (matrix[mid][0] == target)
      return true;
    else if (matrix[mid][0] > target)
      last = mid - 1;
    else { // matrix[mid][0] < target
      if (matrix[mid + 1][0] > target) {
          row = mid;
          break;
      }
      else first = mid + 1;
    }
    if (first == last) row = first;
  }

  return std::binary_search(matrix[row].begin(), matrix[row].end(), target);
}

int main() {
  std::vector<std::vector<int>> m { {1,3,5,7},
                                    {10,11,16,20},
                                    {23, 30, 34, 50} };
  for (auto &v: m) {
    for (int i: v) std::cout << i << ' ';
    std::cout << '\n';
  }
  std::cout << "3 : " << searchMatrix(m, 3) << '\n';
  std::cout << "13 : " << searchMatrix(m, 13) << '\n';
}
