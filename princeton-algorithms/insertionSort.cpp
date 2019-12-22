#include <iostream>

template <typename T>
void sort(T *array, int len) {
  for (int i=0; i<len; ++i) {
    for (int j=(i-1); j>=0; --j) {
      if (array[j] <= array[j+1])
        break;
      std::swap(array[j], array[j+1]);
    }
  }
}

int main() {
  int a[] = {7,10,5,3,8,4,2,9,6};
  for (int i : a) std::cout << i << ' ';
  std::cout << '\n';

  sort(a, sizeof(a)/sizeof(a[0]));

  for (int i : a) std::cout << i << ' ';
  std::cout << '\n';

  std::string s[] = {"xyz", "abc", "ropi", "aaa"};
  for (std::string ss : s) std::cout << ss << ' ';
  std::cout << '\n';

  sort(s, sizeof(s) / sizeof(s[0]));

  for (std::string ss : s) std::cout << ss << ' ';
  std::cout << '\n'; 
}
