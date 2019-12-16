/* You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you
 * need to make up that amount. If the amount of money canot be made up by
 * any combination of the coins, return -1.
 *
 * Runtime: 44 ms, faster than 78.41% of C++ online submissions.
 * Memory usage: 12.5 MB, less than 94.12% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int coinChange(std::vector<int> &coins, int amount) {
  if (amount < 1) return 0;
  std::vector<int> count (amount + 1, amount + 1);
  count[0] = 0;
  for (int i=1; i<(amount + 1); ++i) {
    for (int coin : coins) {
      if (coin <= i)
        count[i] = std::min(count[i], count[i - coin] + 1);
    }
  }
  return (count[amount] > amount) ? -1 : count[amount];
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
