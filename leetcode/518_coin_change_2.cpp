/* You are given coins of different denominations and a total amount of
 * money. Write a function to compute the number of combination that make up
 * that amount. You may assume that you have an infinite number of each kind
 * of coin.
 *
 * Runtime: 8 ms, faster than 76.72% of C++ online submissions.
 * Memory usage: 8.7 MB, less than 71.43% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int change(int amount, std::vector<int> &coins) {
  if (amount < 1) return 1;
  std::vector<int> count (amount + 1, 0);
  count[0] = 1;
  for (int coin : coins) {
    for (int i=1; i<=amount; ++i) {
      if (coin <= i)
        count[i] += count[i - coin];
    }
  }
  return count[amount];
}

int main() {
  std::vector<int> coins {1, 2, 5};
  std::cout << "Coins: ";
  for (int coin : coins) std::cout << coin << ' ';
  std::cout << "\nAmount: 5\n# of ways to give change: ";
  std::cout << change(5, coins) << '\n';
}
