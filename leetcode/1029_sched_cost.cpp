#include <algorithm>
#include <iostream>
#include <vector>

int sched_cost(std::vector<std::vector<int>> &costs) {
  std::sort(costs.begin(), costs.end(),
            [](std::vector<int> x, std::vector<int> y) {
              return x[0] - x[1] < y[0] - y[1]; });
  int sum = 0;
  int len = costs.size();
  for (int i=0; i<len/2; ++i)
    sum += costs[i][0]; 
  for (int i=len/2; i<len; ++i)
    sum += costs[i][1];
  return sum;
}

int main() {
  std::vector<std::vector<int>> v { {10,20}, {30,200}, {400,50}, {30,20} };
  for (auto vv : v) std::cout << vv[0] << ' ' << vv[1] << '\n';
  std::cout << '\n' << sched_cost(v) << '\n';
}
