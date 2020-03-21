/* Design a Phone Directory which supports the following operations:
 *
 * 1. get: Provide a number which is not assigned to anyone.
 * 2. check: Check if a number is available or not.
 * 3. release: Recycle or release a number.
 *
 * Runtime: 44 ms, faster than 96.76% of C++ online submissions.
 * Memory usage: 20.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <queue>
#include <vector>

class PhoneDirectory {
  std::vector<bool> numsTaken;
  std::queue<int> nextNum;
    
public:
  PhoneDirectory(int maxNumbers) : numsTaken(maxNumbers, false) {
    for (int i = 0; i < maxNumbers; ++i) nextNum.push(i);
  }

  int get() {
    if (nextNum.empty()) return -1;
    
    int next = nextNum.front();
    nextNum.pop();
    numsTaken[next] = true;
    return next;
  }
  
  bool check(int number) {
    return !numsTaken[number];
  }
  
  void release(int number) {
    if (!numsTaken[number]) return;
    
    nextNum.push(number);
    numsTaken[number] = false;
  }
};

int main() {
  PhoneDirectory d(3);
  std::cout << "get: " << d.get() << '\n';
  std::cout << "get: " << d.get() << '\n';
  std::cout << "check 2: " << d.check(2) << '\n';
  std::cout << "get: " << d.get() << '\n';
  std::cout << "check 2: " << d.check(2) << '\n';
  std::cout << "release 2" << '\n';
  d.release(2);
  std::cout << "check 2: " << d.check(2) << '\n';
}
