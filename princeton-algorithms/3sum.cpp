#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

void print(const std::vector<int> &a) {
  for (int i=0; i<a.size(); ++i)
    std::cout << a[i] << ' ';
  std::cout << '\n';
}

int binSearch(const std::vector<int> &a, int val, int i, int j) {
  int l = 0;
  int r = a.size() - 1;
  while (l < r) {
    int m = (r - l) / 2 + l;
    while (m == i || m == j)
      m++;
    if (m > r) {
      r = (r - l) / 2 + l - 1;
      continue;
    }
    if (a[m] == val)
      return m;
    if (a[m] > val)
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}

int sum3(std::vector<int> &a) {
  int count = 0;
  print(a);
  std::sort(a.begin(), a.end());
  print(a);

  std::set<std::vector<int>> s;
  int n = a.size();
  for (int i=0; i<n; ++i) {
    for (int j=i+1; j<n; ++j) {
      int k = binSearch(a, -a[i]-a[j], i, j);
      if (k != -1) {
        std::vector<int> v { a[i], a[j], a[k] };
        std::sort(v.begin(), v.end());
        s.insert(v);
      }
    }
  }

  for (auto v : s) {
    for (int i : v)
      std::cout << i << ' ';
    std::cout << '\n';
  }

  return s.size();
}

int main() {
  std::vector<int> a {-10, 20, 0, -7, 30, -5, -20, -3, 5, 10};
  int n = sum3(a);
  std::cout << "# of triples with sum 0: " << n << '\n';
}
