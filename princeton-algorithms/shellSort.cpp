#include <iostream>

template <typename T>
void sort(T *array, int len) {
  int h = 1;
  while (h < len/3) h = 3*h + 1;

  while (h > 0) {
    for (int i=h; i<len; i+=h) {
      for (int j=(i-h); j>=0; j-=h) {
        if (array[j] < array[j+h]) break;
        std::swap(array[j], array[j+h]);
      }
    }
    h = h/3;
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
