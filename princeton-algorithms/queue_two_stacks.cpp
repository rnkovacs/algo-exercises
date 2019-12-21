#include <iostream>
#include <stack>

template <typename T>
class Queue {
  std::stack<T> inbox;
  std::stack<T> outbox;

public:
  void push(T val) {
    std::cout << "Pushing " << val << '\n';
    inbox.push(val);
  }

  void checkFillOutbox() {
     if (outbox.empty()) {
      while (!inbox.empty()) {
        outbox.push(inbox.top());
        inbox.pop();
      }
    } 
  }

  void pop() {
    checkFillOutbox();
    std::cout << "Popping " << outbox.top() << '\n';
    outbox.pop();
  }

  T top() {
    checkFillOutbox();
    return outbox.top();
  }

  void print() const {
    std::cout << "Inbox: ";
    std::stack<T> in = inbox;
    while (!in.empty()) {
      std::cout << in.top() << ' ';
      in.pop();
    }
    std::cout << "\nOutbox: ";
    std::stack<T> out = outbox;
    while (!out.empty()) {
      std::cout << out.top() << ' ';
      out.pop();
    }
    std::cout << "\n\n";
  }
};

int main() {
  Queue<int> q;
  q.push(1);
  q.print();
  q.push(2);
  q.print();
  q.pop();
  q.print();
  q.push(3);
  q.print();
  q.push(4);
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop(); 
  q.print();
}
