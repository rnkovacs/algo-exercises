#include <iostream>
#include <queue>
#include <stack>

class MedianQueue {
  std::priority_queue<int> lower;
  std::priority_queue<int, std::vector<int>, std::greater<int>> higher;

public:
  void print() {
    std::priority_queue<int> lower_cpy = lower;
    std::stack<int> lower_st;

    while (!lower_cpy.empty()) {
      lower_st.push(lower_cpy.top());
      lower_cpy.pop();
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> higher_cpy = higher;

    while (!lower_st.empty()) {
      std::cout << lower_st.top() << ' ';
      lower_st.pop();
    }
    std::cout << "| ";
    while (!higher_cpy.empty()) {
      std::cout << higher_cpy.top() << ' ';
      higher_cpy.pop();
    }
    std::cout << '\n';
  }

  void insert(int val) {
    if (lower.empty() && higher.empty()) {
      lower.push(val);
      return;
    }

    if (lower.empty()) {
      if (val < higher.top())
        lower.push(val);
      else
        higher.push(val);
    }
    else {
      if (val > lower.top())
        higher.push(val);
      else {
        std::cout << "pushed to lower\n";
        lower.push(val);
      }
    }

    if (lower.size() > higher.size() + 1) {
      higher.push(lower.top());
      lower.pop();
      return;
    }
      
    if (higher.size() > lower.size() + 1) {
      lower.push(higher.top());
      higher.pop();
    }
  }

  int findMedian() {
    int size = lower.size() + higher.size();
    if (!(size % 2) || lower.size() > higher.size())
      return lower.top();
    return higher.top();
  }

  void removeMedian() {
    int size = lower.size() + higher.size();
    if (!(size % 2) || lower.size() > higher.size())
      return lower.pop();
    return higher.pop();
  }
};

int main() {
  MedianQueue m;
  m.insert(1);
  m.print();
  std::cout << "median: " << m.findMedian() << '\n';
  m.insert(2);
  m.print();
  std::cout << "median: " << m.findMedian() << '\n';
  m.insert(3);
  m.print();
  std::cout << "median: " << m.findMedian() << '\n';
  m.insert(-1);
  m.print();
  std::cout << "median: " << m.findMedian() << '\n';
  m.insert(42);
  m.print();
  std::cout << "median: " << m.findMedian() << '\n';
  m.removeMedian();
  std::cout << "removed median\n";
  m.print();
  std::cout << "median: " << m.findMedian() << '\n';
  m.removeMedian();
  std::cout << "removed median\n";
  m.print();
}
