#include <iostream>
#include <random>

template <typename T>
class RandomizedQueue {
  T *array;
  int size;
  int capacity;

public:
  RandomizedQueue() : size(0), capacity(4) {
    array = new T[4];
  }

  ~RandomizedQueue() { delete[] array; }

  bool isEmpty() const { return size == 0; }
  int getSize() const { return size; }

  void enqueue(T item) {
    if (size == capacity) {
      capacity *= 2;
      T *newArray = new T[capacity];

      for (int i = 0; i < size; ++i)
        newArray[i] = array[i];

      delete[] array;
      array = newArray;
      std::cout << "copy\n";
    }

    array[size] = item;
    size++;
  }

  T dequeue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dist(0, size - 1);
    int rand_idx = dist(gen);
    T val = array[rand_idx];
    array[rand_idx] = array[size - 1];
    size--;
    return val;
  }

  T sample() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dist(0, size - 1);
    return array[dist(gen)];
  }

  void print() const {
    std::cout << "capacity: " << capacity << "\n";
    for (int i=0; i<size; i++)
      std::cout << array[i] << ' ';
    std::cout << '\n';
  }
};

int main() {
  RandomizedQueue<int> r;
  r.enqueue(1);
  r.print();
  r.enqueue(2);
  r.print();
  r.enqueue(3);
  r.print();
  r.enqueue(4);
  r.print();
  r.enqueue(5);
  r.print();
  std::cout << "sample: " << r.sample() << '\n';
  std::cout << "sample: " << r.sample() << '\n';
  std::cout << "sample: " << r.sample() << '\n';
  r.dequeue();
  r.print();
  r.dequeue();
  r.print();
  r.dequeue();
  r.print();
  r.dequeue();
  r.print();
  r.dequeue();
  r.print();
}
