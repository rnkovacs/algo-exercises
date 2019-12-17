/* Given a matrix of m x n elements, return all elements of the matrix in
 * spiral order.
 *
 * Runtime: 4 ms, faster than 56.51% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
  int N = matrix.size();
  if (N == 0) return {};
  if (N == 1) return matrix[0];
  
  int M = matrix[0].size();
  int firstRow = 0;
  int lastRow = N-1;
  int leftCol = 0;
  int rightCol = M-1;
  
  std::vector<int> v;
  while (firstRow <= lastRow && leftCol <= rightCol) {
    for (int j=leftCol; j<=rightCol; ++j)
      v.push_back(matrix[firstRow][j]);
    
    for (int i=firstRow+1; i<=lastRow; ++i)
      v.push_back(matrix[i][rightCol]);
    
    if (firstRow != lastRow) {
      for (int j=rightCol-1; j>=leftCol; --j)
          v.push_back(matrix[lastRow][j]);
    }
    if (leftCol != rightCol) {
      for (int i=lastRow-1; i>=firstRow+1; --i)
          v.push_back(matrix[i][leftCol]);
    }
    firstRow++;
    rightCol--;
    lastRow--;
    leftCol++;
  }
  return v;
}

int main() {
  std::vector<std::vector<int>> m { {1,2,3}, {4,5,6}, {7,8,9} };
  for (auto v : m) {
    for (int e : v) std::cout << e << ' ';
    std::cout << '\n';
  }
  std::cout << "Elements in spiral order:\n";
  for (int e : spiralOrder(m))
    std::cout << e << ' ';
  std::cout << '\n';
}
