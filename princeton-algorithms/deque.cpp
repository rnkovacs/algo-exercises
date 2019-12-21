#include <iostream>

template <typename T>
struct Node {
  T val;
  Node *prev;
  Node *next;
  Node(const T &val) : val(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class Deque {
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  Deque<T>() : head(nullptr), tail(nullptr), size(0) {}

  bool isEmpty() const { return size == 0; }
  int getSize() const { return size; }

  class Iterator;
  Iterator begin() const { return Iterator(head); }
  Iterator end() const { return Iterator(nullptr); }

  class Iterator {
    Node<T> *current;

  public:
    Iterator() : current(head) {}
    Iterator(Node<T> *node) : current(node) {}

    Iterator &operator++() { // prefix
      if (current) current = current->next;
      return *this;
    }

    Iterator operator++(int) { // postfix
      Iterator before = *this;
      ++(*this);
      return before;
    }

    bool operator==(Iterator other) const {
      return current == other.current;
    }

    bool operator!=(Iterator other) const {
      return !(*this == other);
    }

    T operator*() const { return current->val; }
  };

  void addFirst(const T &item) {
    Node<T> *i = new Node<T>(item);

    if (!head) {
      head = i;
      tail = i;
      size++;
      return;
    }

    i->next = head;
    head->prev = i;
    head = i;
    size++;
  }

  void addLast(const T &item) {
    if (!head) {
      addFirst(item);
      return;
    }

    Node<T> *i = new Node<T>(item);
    tail->next = i;
    i->prev = tail;
    tail = i;
    size++;
  }

  T removeFirst() {
    if (!head) {
      std::cerr << "Attempting to remove from empty list\n";
      return 0;
    }

    Node<T> *i = head;
    head = i->next;
    if (head) head->prev = nullptr;
    delete i;
    size--;
  }

  T removeLast() {
    if (!head) {
      std::cerr << "Attempting to remove from empty list\n";
      return 0;
    }

    Node<T> *i = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    delete i;
    size--;
  }

  void print() const {
    Node<T> *i = head;
    while (i) {
      std::cout << i->val << ' ';
      i = i->next;
    }
    std::cout << '\n';
  }
};

int main() {
  Deque<int> d;
  d.addFirst(3);
  d.print();
  d.addFirst(-1);
  d.print();
  d.addFirst(7);
  d.print();
  d.addLast(42);
  d.print();
  d.addLast(9);
  d.print();

  for (auto it = d.begin(), end = d.end(); it != end; it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  d.removeLast();
  d.print();
  d.removeLast();
  d.print();
  d.removeFirst();
  d.print();
  d.removeFirst();
  d.print();
  d.removeFirst();
  d.print(); 
}
