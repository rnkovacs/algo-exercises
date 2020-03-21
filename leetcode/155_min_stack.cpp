/* Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *   push(x)  - Push element x onto stack.
 *   pop()    - Removes the element on top of the stack.
 *   top()    - Get the top element.
 *   getMin() - Retrieve the minimum element in the stack.
 *
 * Runtime: 28 ms, faster than 91.01% of C++ online submissions.
 * Memory usage: 16.1 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <stack>

class MinStack {
  std::stack<int> nums;
  std::stack<int> mins;
    
public:
  MinStack() {}

  void push(int x) {
    if (mins.empty() || x <= mins.top()) mins.push(x);
    nums.push(x);
  }
  
  void pop() {
    if (nums.top() == mins.top()) mins.pop();
    nums.pop();
  }

  int top() {
    return nums.top();
  }

  int getMin() {
    return mins.top();
  }

  friend std::ostream &operator<<(std::ostream &, const MinStack &);
};

std::ostream &operator<<(std::ostream &os, const MinStack &s) {
  std::stack<int> copy = s.nums;
  std::stack<int> tmp;
  while (!copy.empty()) {
    tmp.push(copy.top());
    copy.pop();
  }
  while (!tmp.empty()) {
    std::cout << tmp.top() << ' ';
    tmp.pop();
  }
  std::cout << '\n';
}

int main() {
  MinStack s;
  s.push(-2);
  std::cout << s;
  s.push(0);
  std::cout << s;
  s.push(-3);
  std::cout << s;
  std::cout << "min: " << s.getMin() << '\n';
  s.pop();
  std::cout << s;
  std::cout << "top: " << s.top() << '\n';
  std::cout << "min: " << s.getMin() << '\n';
}
