/* There are a row of n houses, each house can be painted with one of the
 * three colors: red, blue or green. The cost of painting each house with
 * a certain color is different. You have to paint all the houses such that
 * no two adjacent houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by
 * a n x 3 cost matrix. For example, costs[0][0] is the cost of painting
 * house 0 with color red; costs[1][2] is the cost of painting house 1 with
 * color green, and so on... Find the minimum cost to paint all houses.
 * 
 * Runtime: 8 ms, faster than 74.12% of C++ online submissions.
 * Memory usage: 8.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int minCost(std::vector<std::vector<int>> &costs) {
  if (costs.empty()) return 0;
  int nHouses = costs.size();
  
  for (int house = nHouses - 2; house >= 0; --house) {
    costs[house][0] += std::min(costs[house + 1][1], costs[house + 1][2]);
    costs[house][1] += std::min(costs[house + 1][0], costs[house + 1][2]);
    costs[house][2] += std::min(costs[house + 1][0], costs[house + 1][1]);
  }
  
  int minAux = std::min(costs[0][0], costs[0][1]);
  return std::min(minAux, costs[0][2]);
}

int main() {
  std::vector<std::vector<int>> costs { {17,2,17},
                                        {16,16,5},
                                        {14,3,19} };
  std::cout << minCost(costs) << '\n';
}
