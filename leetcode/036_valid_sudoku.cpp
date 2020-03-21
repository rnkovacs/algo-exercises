/* Determine if a 9x9 Sudoku board is valid. Only the filled cells
 * need to be validated according to the following rules:
 *
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the 9 3x3 sub-boxes of the grid must contain the digits
 * 1-9 without repetition.
 *
 * The Sudoku board could be partially filled, where empty cells are
 * filled with the character '.'.
 *
 * Runtime: 12 ms, faster than 90.83% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool isValidField(const std::vector<std::vector<char>> &board,
                  std::vector<bool> &check, int row, int col) {
  if (board[row][col] == '.')
    return true;

  int numIdx = board[row][col] - '1';
  if (check[numIdx])
    return false;

  check[numIdx] = true;
  return true;
}
  
bool isValidSudoku(std::vector<std::vector<char>> &board) {
  // Check rows.
  for (int row = 0; row < 9; ++row) {
    std::vector<bool> check(9, false);
    for (int col = 0; col < 9; ++col) {
      if (!isValidField(board, check, row, col))
        return false;
    }
  }
  // Check columns.
  for (int col = 0; col < 9; ++col) {
    std::vector<bool> check(9, false);
    for (int row = 0; row < 9; ++row) {
      if (!isValidField(board, check, row, col))
        return false;
    }
  }
  // Check squares.
  for (int bigIdx = 0; bigIdx < 9; ++bigIdx) {
    std::vector<bool> check(9, false);
    for (int idx = 0; idx < 9; ++idx) {
      int row = (bigIdx / 3) * 3 + idx / 3;
      int col = (bigIdx % 3) * 3 + idx % 3;
      if (!isValidField(board, check, row, col))
        return false;
    }
  }
  return true;
}

int main() {
  std::vector<std::vector<char>> sudoku {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  for (auto &v: sudoku) {
    for (char c: v)
      std::cout << c << ' ';
    std::cout << '\n';
  }
  std::cout << "is valid: " << isValidSudoku(sudoku) << '\n';
}
