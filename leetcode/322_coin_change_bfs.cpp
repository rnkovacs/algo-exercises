/* You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you
 * need to make up that amount. If the amount of money canot be made up by
 * any combination of the coins, return -1.
 *
 * Runtime: 276 ms, faster than 8.05% of C++ online submissions.
 * Memory usage: 63.4 MB, less than 5.88% of C++ online submissions.
 */

#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>

int coinChange(std::vector<int>& coins, int amount) {
  if (amount < 1) return 0;

  std::deque<std::pair<int, int>> q;
  std::unordered_set<int> seen;
  
  q.push_back({amount, 0});
  seen.insert(amount);
  
  while (!q.empty()) {
    int current = q.front().first;
    int level = q.front().second;
    q.pop_front();

    for (int coin : coins) {
      int value = current - coin;
      if (value < 0)
        continue;
      if (value == 0)
        return level + 1;
      if (!seen.count(value)) {
        q.push_back({value, level + 1});
        seen.insert(value);
      }
    }
  }

  return -1;
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
