/* Given a stream of integers and a window size, calculate the moving average
 * of all integers in the sliding window.
 *
 * Runtime: 32 ms, faster than 79.57% of C++ online submissions.
 * Memory usage: 14.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <queue>

class MovingAverage {
  std::queue<int> q;
  int windowSize;
  double sum;
    
public:
  MovingAverage(int size): windowSize(size), sum(0) {}
  
  double next(int val) {
    if (q.size() == windowSize) {
      sum -= q.front();
      q.pop();
    }
    
    q.push(val);
    sum += val;
    return sum / q.size();
  }
};

int main() {
  MovingAverage m(3);
  std::cout << " 1: " << m.next(1) << '\n';
  std::cout << "10: " << m.next(10) << '\n';
  std::cout << " 3: " << m.next(3) << '\n';
  std::cout << " 5: " << m.next(5) << '\n';
}
