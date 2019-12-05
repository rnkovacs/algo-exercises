#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::vector<int>> taxicab_numbers(int n) {
  std::vector<std::vector<int>> nums;
  std::unordered_multimap<int, std::pair<int, int>> sums;

  for (int i=0; i<n; ++i) {
    for (int j=0; j<i+1; ++j) {
      int sum = i*i*i + j*j*j;
      auto it = sums.find(sum);
      if (it != sums.end())
        nums.push_back( {j, i, (*it).second.second, (*it).second.first} );
      sums.insert( {i*i*i + j*j*j, {i, j}} );
    }
  }
  
  return nums;
}

int main() {
  for (auto set : taxicab_numbers(50)) {
    for (int i : set)
      std::cout << i << ' ';
    std::cout << '\n';
  }
}
