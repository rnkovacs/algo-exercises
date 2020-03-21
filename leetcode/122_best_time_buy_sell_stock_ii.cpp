/* Say you have an array for which the ith element is the price of a given
 * stock on day i. Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like (i.e., buy one and sell
 * one share of the stock multiple times).
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Runtime: 4 ms, faster than 98.08% of C++ online submissions.
 * Memory usage: 8.7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
  int N = prices.size();
  if (N < 2) return 0;

  int profit = 0;
  for (int i = 1; i < N; ++i) {
    if (prices[i-1] < prices[i])
      profit += prices[i] - prices[i-1];
  }
  
  return profit;
}

int main() {
  std::vector<int> prices {7,1,5,3,6,4};
  for (int i: prices) std::cout << i << ' ';
  std::cout << "\nmax profit: " << maxProfit(prices) << '\n';
}
