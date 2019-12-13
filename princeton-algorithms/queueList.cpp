#include <iostream>

struct Node {
  int val;
  Node *next;
  Node(int val) : val(val), next(nullptr) {}
};

class Queue {
  Node *first;
  Node *last;

public:
  Queue() : first(nullptr), last(nullptr) {}

  bool isEmpty() { return !first; }

  void enqueue(int val) {
    Node *n = new Node(val);

    if (isEmpty()) {
      first = n;
      last = first;
      return;
    }

    Node *oldLast = last;
    last = n;
    oldLast->next = last;
    return;
  }

  int dequeue() {
    if (isEmpty()) {
      std::cerr << "can't dequeue from empty queue\n";
      return -1;
    }

    Node *n = first;
    first = first->next;
    int val = n->val;
    delete n;
    return val;
  }
};

int main() {
  Queue q;
  q.enqueue(3);
  q.enqueue(-1);
  q.enqueue(2);
  std::cout << q.dequeue() << ' ';
  std::cout << q.dequeue() << ' ';
  std::cout << q.dequeue() << '\n';
}
