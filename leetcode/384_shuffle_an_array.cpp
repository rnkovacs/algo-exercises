/* Shuffle a set of numbers without duplicates.
 *
 * Runtime: 192 ms, faster than 96.99% of C++ online submissions.
 * Memory usage: 29.6 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <random>
#include <vector>

class Solution {
  std::vector<int> orig;
  std::random_device rd;
  std::mt19937 gen;
    
public:
  Solution(std::vector<int> &nums) : orig(nums), rd(), gen(rd()) {}
    
  std::vector<int> reset() {
    return orig;
  }
    
  std::vector<int> shuffle() {
    std::vector<int> shuffled = orig;
    for (int i = 0; i < orig.size(); ++i) {
      std::uniform_int_distribution<> dis(0, i);
      std::swap(shuffled[i], shuffled[dis(gen)]);
    }
    return shuffled;
  }
};

int main() {
  std::vector<int> nums {1, 2, 3};
  Solution obj(nums);
  std::vector<int> orig = obj.reset();
  for (int i: orig) std::cout << i << ' '; std::cout << '\n';
  std::vector<int> shuffled = obj.shuffle();
  for (int i: shuffled) std::cout << i << ' '; std::cout << '\n';
  shuffled = obj.shuffle(); 
  for (int i: shuffled) std::cout << i << ' '; std::cout << '\n';
  shuffled = obj.shuffle(); 
  for (int i: shuffled) std::cout << i << ' '; std::cout << '\n';
  shuffled = obj.shuffle(); 
}
