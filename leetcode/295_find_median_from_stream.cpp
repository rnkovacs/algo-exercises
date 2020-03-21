/* Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the
 * two middle values.
 * Design a data structure that supports the following two operations:
 *   - Add an integer number from the data stream to the data structure.
 *   - Return the median of all elements so far.
 *
 * Runtime: 136 ms, faster than 97.67% of C++ online submissions.
 * Memory usage: 41.6 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
  std::priority_queue<int> lower;
  std::priority_queue<int, std::vector<int>, std::greater<int>> higher;
    
public:
  void addNum(int num) {
    if (lower.empty() && higher.empty()) {
      lower.push(num);
      return;
    }
    
    if (num >= lower.top()) higher.push(num);
    else                    lower.push(num);

    if (lower.size() > higher.size() + 1) {
      higher.push(lower.top());
      lower.pop();
    }
    else if (higher.size() > lower.size() + 1) {
      lower.push(higher.top());
      higher.pop();
    }
  }
    
  double findMedian() {
    if (lower.size() == higher.size())
      return (double) lower.top() / 2 + higher.top() / 2;
    
    return (lower.size() > higher.size()) ? lower.top() : higher.top();
  }
};

int main() {
  MedianFinder mf = MedianFinder();
  mf.addNum(2);
  std::cout << mf.findMedian() << '\n';
  mf.addNum(3);
  std::cout << mf.findMedian() << '\n';
  mf.addNum(4);
  std::cout << mf.findMedian() << '\n';
}
