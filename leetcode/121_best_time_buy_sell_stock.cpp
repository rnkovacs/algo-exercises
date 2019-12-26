/* You have an array where the ith element is the price of a given stock
 * on day i. If you were only permitted to complete at most one transaction
 * (i.e. buy one and sell one), design an algorithm to find the maximum
 * profit.
 *
 * Runtime: 4 ms, faster than 98.48% of C++ online submissions.
 * Memory usage: 9.5 MB, less than 90.83% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
  int N = prices.size();
  if (N < 2) return 0;

  int minPrice = prices[0];
  int maxProfit = 0;
  
  for (int i=1; i<N; ++i) {
    // Price is larger than minPrice
    if (prices[i] - minPrice > maxProfit)
      maxProfit = prices[i] - minPrice;
    
    // Price is smaller than minPrice
    else if (prices[i] < minPrice)
      minPrice = prices[i];
  }
  
  return maxProfit;
}

int main() {
  std::vector<int> v {7,1,5,3,6,4};
  std::cout << maxProfit(v) << '\n';
}
