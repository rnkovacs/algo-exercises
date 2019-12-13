#include <algorithm>
#include <iostream>
#include <vector>

int partition(std::vector<int> &v, int l, int r) {
  std::cout << "\nPartitioning from " << l << " to " << r << '\n';
  int i = l;
  int j = r + 1;
  while (true) {
    while (v[++i] < v[l])
      if (i == r) break;

    while (v[--j] > v[l])
      if (j == l) break;

    if (i >= j) break;
    std::swap(v[i], v[j]);
    std::cout << " swapped " << v[i] << " and " << v[j] << '\n';
  }

  std::swap(v[l], v[j]);
  std::cout << " swapped " << v[l] << " and " << v[j] << '\n';
  return j;
}

int select(std::vector<int> &v, int order) {
  std::random_shuffle(v.begin(), v.end());
  for (int e : v) std::cout << e << ' '; std::cout << '\n';
  int l = 0;
  int r = v.size() - 1;
  while (r > l) {
    int pivot = partition(v, l, r);
    std::cout << "Pivot is " << pivot << '\n';
    if (pivot < order)
      l = pivot + 1;
    else if (pivot > order)
      r = pivot - 1;
    else
      return v[order];
  }
  return v[order];
}

int main() {
  //std::vector<int> v { 3, 6, -2, 1, 7, 7, 3 };
  std::vector<int> v { 3, 3, 3, 3, 3, 3, 3 };
  // Select smallest.
  std::cout << select(v, 0) << '\n';
  // Select largest.
  //std::cout << select(v, v.size() - 1) << '\n';
  // Select median.
  //std::cout << select(v, v.size() / 2) << '\n'; 
}
