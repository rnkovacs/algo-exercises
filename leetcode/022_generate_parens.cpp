/* Given n pairs of parentheses, write a function to generate all
 * combinations of well-formed parentheses.
 *
 * Runtime: 4 ms, faster than 87.02% of C++ online submissions.
 * Memory usage: 15.1 MB, less than 80.17% of C++ online submissions.
 */

#include <vector>

void generateParenthesis(int n, int open, int closed, std::string s,
                         std::vector<std::string> &res) {
  if (s.size() == 2 * n) {
      res.push_back(s);
      return;
  }
  
  if (open < n)
    generateParenthesis(n, open + 1, closed, s + "(", res);
  if (closed < n && closed < open)
    generateParenthesis(n, open, closed + 1, s + ")", res);
}

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> res;
  generateParenthesis(n, 0, 0, "", res);
  return res;
}
