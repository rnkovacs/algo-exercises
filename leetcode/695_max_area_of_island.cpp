/* Given a non-empty 2D array grid of 0's and 1's, an island is a group
 * of 1's (representing land) connected 4-directionally (horizontal or
 * vertical.) You may assume all four edges of the grid are surrounded by
 * water.
 *
 * Find the maximum area of an island in the given 2D array. (If there is
 * no island, the maximum area is 0.)
 *
 * Runtime:
 * Memory usage:
 */

#include <vector>

int nRows;
int nCols;

void search(std::vector<std::vector<int>> &grid, int row, int col, int &area) {
  if (grid[row][col] == 0 || grid[row][col] == -1)
    return;
  
  grid[row][col] = -1;
  ++area;
  
  if (col > 0)        search(grid, row, col-1, area);
  if (row > 0)        search(grid, row-1, col, area);
  if (col < nCols-1)  search(grid, row, col+1, area);
  if (row < nRows-1)  search(grid, row+1, col, area);
}

int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
  nRows = grid.size();
  if (!nRows) return 0;
  nCols = grid[0].size();
  if (!nCols) return 0;
  
  int maxArea = 0;
  for (int row = 0; row < nRows; ++row) {
    for (int col = 0; col < nCols; ++col) {
      int area = 0;
      if (grid[row][col] == 1) search(grid, row, col, area);
      maxArea = std::max(area, maxArea);
    }
  }
  return maxArea;
}
