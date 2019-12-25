#include <iostream>
#include <random>

template <typename T>
void shuffle(T *array, int len) {
  std::random_device rd;
  std::mt19937 gen(rd());
  for (int i=0; i<len; ++i) {
    std::uniform_int_distribution<> dis(0, i);
    std::swap(array[dis(gen)], array[i]);
  }
}

int main() {
  int a[] = {7,10,5,3,8,4,2,9,6};
  for (int i : a) std::cout << i << ' ';
  std::cout << '\n';

  shuffle(a, sizeof(a) / sizeof(a[0]));

  for (int i : a) std::cout << i << ' ';
  std::cout << '\n'; 
}
