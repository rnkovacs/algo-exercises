#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Field {
  int i;
  int j;
  int sum;
  Field(int i, int j) : i(i), j(j), sum(i*i*i + j*j*j) {}
};

struct FieldGreater {
  bool operator()(Field a, Field b) {
    return a.sum > b.sum;
  }
};

std::vector<std::pair<Field, Field>> taxicab_numbers(int n) {
  std::vector<std::pair<Field, Field>> nums;
  std::priority_queue<Field, std::vector<Field>, FieldGreater> sums;
  
  for (int i=0; i<n; ++i)
    sums.push(Field((i+1), (i+1)));

  Field prev = Field(0, 0);

  while (!sums.empty()) {
    Field t = sums.top();
    sums.pop();

    if (t.sum == prev.sum)
      nums.push_back({prev, t});
    prev = t;

    if (t.j < n)
      sums.push(Field(t.i, t.j+1));
  }
  
  return nums;
}

int main() {
  for (auto t : taxicab_numbers(13)) {
    std::cout << t.first.i << ' ' << t.first.j << ' '
              << t.second.i << ' ' << t.second.j << '\n';
  }
}
