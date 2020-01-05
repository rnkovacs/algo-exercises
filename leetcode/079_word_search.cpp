/* Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 *
 * Runtime: 12 ms, faster than 99.54% of C++ online submissions.
 * Memory usage: 10 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

bool find(std::vector<std::vector<char>> &b, int x, int y,
          const std::string &word, int w, int N, int M) {
    if (++w == word.size()) return true;
    
    char tmp = b[x][y];
    b[x][y] = '#';
    
    if (   (x-1 >= 0 && b[x-1][y] == word[w] && find(b, x-1, y, word, w, N, M))
        || (y+1 < M && b[x][y+1] == word[w] && find(b, x, y+1, word, w, N, M))
        || (x+1 < N && b[x+1][y] == word[w] && find(b, x+1, y, word, w, N, M))
        || (y-1 >= 0 && b[x][y-1] == word[w] && find(b, x, y-1, word, w, N, M))) {
      b[x][y] = tmp;
      return true;
    }

    b[x][y] = tmp;
    return false;
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
    int N = board.size();
    if (!N) return false;
    int M = board[0].size();
    if (!M) return false;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int w = 0;
            if (board[i][j] == word[w] && find(board, i, j, word, w, N, M))
                return true;
        }
    }
    
    return false;
}

int main() {
  std::vector<std::vector<char>> board = { {'A', 'B', 'C', 'E'},
                                           {'S', 'F', 'C', 'S'},
                                           {'A', 'D', 'E', 'E'} };
  for (auto row : board) {
    for (char ch : row)
      std::cout << ch << ' ';
    std::cout << '\n';
  }

  std::cout << "ABCCED exists? " << exist(board, "ABCCED") << '\n';
  for (auto row : board) {
    for (char ch : row)
      std::cout << ch << ' ';
    std::cout << '\n';
  }
  std::cout << "SEE exists? " << exist(board, "SEE") << '\n';
  for (auto row : board) {
    for (char ch : row)
      std::cout << ch << ' ';
    std::cout << '\n';
  }
  std::cout << "ABCB exists? " << exist(board, "ABCB") << '\n';
}
