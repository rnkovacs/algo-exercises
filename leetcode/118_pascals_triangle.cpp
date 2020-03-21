/* Given a non-negative integer numRows, generate the first numRows of
 * Pascal's triangle. In Pascal's triangle, each number is the sum of the two
 * numbers directly above it.
 *
 * Runtime: 4 ms, faster than 59.61% of C++ online submissions.
 * Memory usage: 8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
  std::vector<std::vector<int>> triangle;
  if (numRows == 0) return triangle;
  
  triangle.push_back({1});
  if (numRows == 1) return triangle;
  
  triangle.push_back({1,1});
  
  for (int row = 1; row < numRows - 1; ++row) {
    std::vector<int> v;
    v.push_back(1);
    
    for (int i = 1; i < triangle[row].size(); ++i)
      v.push_back(triangle[row][i] + triangle[row][i - 1]);
    
    v.push_back(1);
    triangle.emplace_back(v);
  }
  
  return triangle;
}

int main() {
  for (const auto &v: generate(5)) {
    for (int i: v) std::cout << i << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';
}
