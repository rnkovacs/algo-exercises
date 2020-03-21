/* Count the number of prime numbers less than a non-negative number, n.
 *
 * Runtime: 48 ms, faster than 69.41% of C++ online submissions.
 * Memory usage: 20.7 MB, less than 8.33% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int countPrimes(int n) {
  if (n <= 2) return 0;

  // 0, 1, ..., n-1 // index == number
  // 1 is prime, 0 is not prime
  std::vector<int> nums(n, 1);
  auto pIt = nums.begin() + 2;

  while (pIt != nums.end()) {
    int prime = pIt - nums.begin();

    // mark all multiples of p as not prime
    for (int mul = 2 * prime; mul < n; mul += prime)
      nums[mul] = 0;

    // find next prime
    pIt = std::find(pIt + 1, nums.end(), 1);
  }

  return std::count(nums.begin(), nums.end(), 1) - 2; // 0 and 1
}

int main() {
  std::cout << "# of primes up to 10: " << countPrimes(10) << '\n';
}
