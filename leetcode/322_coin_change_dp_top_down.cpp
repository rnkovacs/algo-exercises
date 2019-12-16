/* You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you
 * need to make up that amount. If the amount of money canot be made up by
 * any combination of the coins, return -1.
 *
 * Runtime: 84 ms, faster than 16.59% of C++ online submissions.
 * Memory usage: 12.8 MB, less than 39.22% of C++ online submissions.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int coinChange(const std::vector<int> &coins, int amount, std::vector<int> &cache) {
  if (amount < 0) return -1;
  if (amount == 0) return 0;
  if (cache[amount - 1] != 0)
    return cache[amount - 1];

  int minNumCoins = INT_MAX;
  for (int coin : coins) {
    int numWithoutCoin = coinChange(coins, amount - coin, cache);
    if (numWithoutCoin < 0)
      continue;
    if (numWithoutCoin < minNumCoins)
      minNumCoins = numWithoutCoin + 1;
  }
  minNumCoins = (minNumCoins == INT_MAX) ? -1 : minNumCoins;
  
  cache[amount - 1] = minNumCoins;
  return minNumCoins;
}

int coinChange(std::vector<int> &coins, int amount) {
  if (amount < 1) return 0;
  std::vector<int> cache (amount, 0);
  std::sort(coins.begin(), coins.end(), std::greater<int>());
  return coinChange(coins, amount, cache);
}

int main() {
  std::vector<int> coins { 1, 2, 5 };
  std::cout << "Coins: ";
  for (int coin : coins) std::cout << coin << ' ';
  std::cout << "\nAmount: 11\nMin number of coins: ";
  std::cout << coinChange(coins, 11) << "\n\n";
 
  std::vector<int> coins2 { 186, 419, 83, 408 };
  std::cout << "Coins: ";
  for (int coin : coins2) std::cout << coin << ' ';
  std::cout << "\nAmount: 6249\nMin number of coins: ";
  std::cout << coinChange(coins2, 6249) << '\n';
}
