/* Given two 1d vectors, implement an iterator to return their elements
 * alternately.
 *
 * Runtime: 16 ms, faster than 90.10% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

class ZigzagIterator {
  bool oneComes;
  std::vector<int>::iterator it1;
  std::vector<int>::iterator end1;
  std::vector<int>::iterator it2;
  std::vector<int>::iterator end2;

public:
  ZigzagIterator(std::vector<int> &v1, std::vector<int> &v2) : oneComes(true),
    it1(v1.begin()), end1(v1.end()), it2(v2.begin()), end2(v2.end()) {}

  int next() {
    if (oneComes) {
        oneComes = !oneComes;
        if (it1 != end1) return *it1++;
        // should only be called if one of them is valid
        return *it2++;
    }
    oneComes = !oneComes;
    if (it2 != end2) return *it2++;
    return *it1++;
  }

  bool hasNext() {
    return it1 != end1 || it2 != end2;
  }
};

int main() {
  std::vector<int> v1 {1,2};
  std::vector<int> v2 {3,4,5,6};
  ZigzagIterator z(v1, v2);
  while (z.hasNext())
    std::cout << z.next() << ' ';
  std::cout << '\n';
}
