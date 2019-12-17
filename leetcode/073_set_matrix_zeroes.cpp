#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
  int rows = matrix.size();
  if (!rows) return;

  int cols = matrix[0].size();
  bool eraseFirstRow = false;

  // Mark rows & columns to zero out
  for (int i=0; i<rows; ++i) {
    for (int j=0; j<cols; ++j) {
      if (matrix[i][j] == 0) {
        // First row indicators are special
        if (i == 0) eraseFirstRow = true;
        else matrix[i][0] = 0;
        // Column indicators work normally
        matrix[0][j] = 0;
      }
    }
  }

  // Erase columns except for first row & first column
  for (int j=1; j<cols; ++j) {
    if (matrix[0][j] == 0) {
      for (int i=1; i<rows; ++i) {
        matrix[i][j] = 0;
      }
    }
  }
  // Erase rows except for first row & first column
  for (int i=1; i<rows; ++i) {
    if (matrix[i][0] == 0) {
      for (int j=1; j<cols; ++j) {
        matrix[i][j] = 0;
      }
    }
  }
  // Erase first column
  if (matrix[0][0] == 0) {
    for (int i=0; i<rows; ++i) {
      matrix[i][0] = 0;
    }
  }
  // Erase first row
  if (eraseFirstRow) {
    for (int j=0; j<cols; ++j) {
      matrix[0][j] = 0;
    }
  }
}

int main() {
  std::vector<std::vector<int>> v { {0,1,2,0}, {3,4,5,2}, {1,3,1,5} };
  for (auto vv : v) {
    for (int i : vv)
      std::cout << i << ' ';
    std::cout << '\n';
  }
  setZeroes(v);
  std::cout << '\n';
  for (auto vv : v) {
    for (int i : vv)
      std::cout << i << ' ';
    std::cout << '\n';
  }
}
