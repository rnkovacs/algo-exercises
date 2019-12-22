#include <iostream>

template <typename T>
void sort(T *array, int len) {
  for (int i=0; i<len; ++i) {
    int minIdx = i;
    for (int j=i; j<len; ++j) {
      if (array[j] < array[minIdx])
        minIdx = j;
    }
    std::swap(array[i], array[minIdx]);
  }
}

int main() {
  int a[] = {7,10,5,3,8,4,2,9,6};
  for (int i : a) std::cout << i << ' ';
  std::cout << '\n';
  
  sort(a, sizeof(a)/sizeof(a[0]));
  
  for (int i : a) std::cout << i << ' ';
  std::cout << '\n';

  std::string s[] = {"abc", "xyz", "def", "rpo"};
  for (std::string ss : s) std::cout << ss << ' ';
  std::cout << '\n';

  sort(s, sizeof(s)/sizeof(s[0]));

  for (std::string ss : s) std::cout << ss << ' ';
  std::cout << '\n';
}
