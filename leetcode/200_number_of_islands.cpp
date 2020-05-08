/* Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges
 * of the grid are all surrounded by water.
 *
 * Runtime: 8 ms, faster than 99.13% of C++ online submissions.
 * Memory usage: 8.3 MB, less than 100.00% of C++ online submissions.
 */

#include <vector>

int nRows;
int nCols;

void search(std::vector<std::vector<char>> &grid, int row, int col) {
  int val = grid[row][col];
  if (val == '0' || val == '#') return;
  
  grid[row][col] = '#';
  if (col > 0)        search(grid, row, col-1);
  if (row > 0)        search(grid, row-1, col);
  if (col < nCols-1)  search(grid, row, col+1);
  if (row < nRows-1)  search(grid, row+1, col);
}

int numIslands(std::vector<std::vector<char>> &grid) {
  nRows = grid.size();
  if (!nRows) return 0;
  nCols = grid[0].size();
  if (!nCols) return 0;
  
  int num = 0;
  for (int row = 0; row < nRows; ++row) {
      for (int col = 0; col < nCols; ++col) {
          if (grid[row][col] == '1') {
              search(grid, row, col);
              ++num;
          }
      }
  }
  return num;
}
