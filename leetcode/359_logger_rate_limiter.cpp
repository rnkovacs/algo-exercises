/* Design a logger system that receive stream of messages along with its
 * timestamps, each message should be printed if and only if it is not
 * printed in the last 10 seconds.
 *
 * Given a message and a timestamp (in seconds granularity), return true
 * if the message should be printed in the given timestamp, otherwise
 * returns false.
 *
 * It is possible that several messages arrive roughly at the same time.
 *
 * Runtime: 84 ms, faster than 93.80% of C++ online submissions.
 * Memory usage: 31.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <unordered_map>

class Logger {
  std::unordered_map<std::string, int> lastPrinted;
    
public:
  bool shouldPrintMessage(int timestamp, std::string message) {
    if (lastPrinted.find(message) == lastPrinted.end() ||
        timestamp - lastPrinted[message] >= 10) {
      lastPrinted[message] = timestamp;
      return true;
    }
    return false;
  }
};

int main() {
  Logger l;
  std::cout << "1, foo: " << l.shouldPrintMessage(1, "foo") << '\n';
  std::cout << "2, bar: " << l.shouldPrintMessage(2, "bar") << '\n';
  std::cout << "3, foo: " << l.shouldPrintMessage(3, "foo") << '\n';
  std::cout << "8, bar: " << l.shouldPrintMessage(8, "bar") << '\n';
  std::cout << "10, foo: " << l.shouldPrintMessage(10, "foo") << '\n';
  std::cout << "11, foo: " << l.shouldPrintMessage(11, "foo") << '\n';
}
