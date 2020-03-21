/* Design a Tic-tac-toe game that is played between two players on a
 * n x n grid. You may assume the following rules:
 *
 * 1. A move is guaranteed to be valid and is placed on an empty block.
 * 2. Once a winning condition is reached, no more moves is allowed.
 * 3. A player who succeeds in placing n of their marks in a horizontal,
 *    vertical, or diagonal row wins the game.
 *
 * Runtime: 44 ms, faster than 21.74% of C++ online submissions.
 * Memory usage: 19.2 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

class TicTacToe {
  int n;
  std::vector<int> rows;
  std::vector<int> cols;
  std::vector<int> diags;
  // rows: # of marks of a player in row i (p1: rows[i], p2: rows[3 + i])
  // cols: # of marks of a player in col i (p1: cols[i], p2: cols[3 + i])
  // diags: # of marks of a player in diagonal i (p1: diags[i], p2: diags[2 + i])

  int checkBoard() {
    auto it = std::find(rows.begin(), rows.end(), n);
    if (it != rows.end()) return std::distance(rows.begin(), it) < n ? 1 : 2;
    
    it = std::find(cols.begin(), cols.end(), n);
    if (it != cols.end()) return std::distance(cols.begin(), it) < n ? 1 : 2;
    
    it = std::find(diags.begin(), diags.end(), n);
    if (it != diags.end()) return std::distance(diags.begin(), it) < 2 ? 1 : 2;
    
    return 0;
  }
    
public:
  TicTacToe(int n) : n(n), rows(n * 2, 0), cols(n * 2, 0), diags(4, 0) {}
  
  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */
  int move(int row, int col, int player) {
    std::cout << "player " << player << " moves ("
              << row << ", " << col << ")\n";

    int diff = (player == 1) ? 0 : n;
    ++rows[row + diff]; // _ _ _ | 1 1 _
    ++cols[col + diff]; // _ _ _ | _ 1 1
    
    diff = (player == 1) ? 0 : 2; // _ _ | 1 3
    if (row == col)           ++diags[0 + diff];
    if (row == (n - 1 - col)) ++diags[1 + diff];
    
    return checkBoard();
  }
};

int main() {
  TicTacToe t(3);
  std::cout << t.move(0, 0, 1) << '\n';
  std::cout << t.move(0, 2, 2) << '\n';
  std::cout << t.move(2, 2, 1) << '\n';
  std::cout << t.move(1, 1, 2) << '\n';
  std::cout << t.move(2, 0, 1) << '\n';
  std::cout << t.move(1, 0, 2) << '\n';
  std::cout << t.move(2, 1, 1) << '\n';
}
