/* Implement the following operations of a queue using stacks.
 *
 * - push(x) -- Push element x to the back of queue.
 * - pop() -- Removes the element from in front of queue.
 * - peek() -- Get the front element.
 * - empty() -- Return whether the queue is empty.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 8.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <stack>

class MyQueue {
  std::stack<int> pushStack;
  std::stack<int> popStack;
  
  void transfer() {
    while (!pushStack.empty()) {
      popStack.push(pushStack.top());
      pushStack.pop();
    }
  }
    
public:
  void push(int x) {
    pushStack.push(x);
  }
  
  int pop() {
    if (popStack.empty()) transfer();
    int val = popStack.top();
    popStack.pop();
    return val;
  }
  
  int peek() {
    if (popStack.empty()) transfer();
    return popStack.top();
  }
  
  bool empty() {
    return pushStack.empty() && popStack.empty();
  }
};

int main() {
  MyQueue q;
  q.push(1);
  std::cout << "pushed 1\n";
  q.push(2);
  std::cout << "pushed 2\n";
  std::cout << "peek: " << q.peek() << '\n';
  std::cout << "pop: " << q.pop() << '\n';
  std::cout << "empty: " << q.empty() << '\n';
}
