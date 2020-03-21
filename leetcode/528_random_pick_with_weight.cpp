/* Given an array w of positive integers, where w[i] describes the weight
 * of index i, write a function pickIndex which randomly picks an index
 * in proportion to its weight.
 *
 * Runtime: 144 ms, faster than 63.80% of C++ online submissions.
 * Memory usage: 32.5 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

class WeightedPick {
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<> dist;
  std::vector<int> &weights;
    
public:
  WeightedPick(std::vector<int> &w): gen(rd()), weights(w) {
    for (int i = 1; i < w.size(); ++i) weights[i] += weights[i-1];
    dist = std::uniform_int_distribution<>(1, weights[weights.size() - 1]);
  }
  
  int pickIndex() {
    auto it = std::lower_bound(weights.begin(), weights.end(), dist(gen));
    return std::distance(weights.begin(), it);
  }
};

int main() {
  std::vector<int> w {1, 3};
  for (int i: w) std::cout << i << ' '; std::cout << '\n';
  WeightedPick p(w);
  std::cout << "picked index: " << p.pickIndex() << '\n';
  std::cout << "picked index: " << p.pickIndex() << '\n';
  std::cout << "picked index: " << p.pickIndex() << '\n';
}
