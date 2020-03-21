/* You have an array where the ith element is the price of a given stock
 * on day i. If you were only permitted to complete at most one transaction
 * (i.e. buy one and sell one), design an algorithm to find the maximum
 * profit.
 *
 * Runtime: 4 ms, faster than 98.20% of C++ online submissions.
 * Memory usage: 8.6 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
  if (prices.size() < 2) return 0;

  int buy = prices[0];
  int profit = 0;
  
  for (int i = 1; i < prices.size(); ++i) {
    buy = std::min(buy, prices[i]);
    profit = std::max(profit, prices[i] - buy);
  }
  
  return profit;
}

int main() {
  std::vector<int> v {7,1,5,3,6,4};
  std::cout << maxProfit(v) << '\n';
}
