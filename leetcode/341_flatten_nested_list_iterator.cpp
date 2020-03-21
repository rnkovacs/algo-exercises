/* Given a nested list of integers, implement an iterator to flatten it.
 *
 * Each element is either an integer, or a list -- whose elements may also
 * be integers or other lists.
 *
 * Runtime: 16 ms, faster than 91.73% of C++ online submissions.
 * Memory usage: 17.7 MB, less than 63.64% of C++ online submissions.
 */

#include <iostream>
#include <stack>
#include <vector>

class NestedInteger {
  std::vector<NestedInteger> v;
  int val;

public:
  NestedInteger(int val, std::vector<NestedInteger> v): val(val), v(v) {}

  bool isInteger() const { return v.empty(); }
  int getInteger() const { return val; }
  const std::vector<NestedInteger> &getList() const { return v; }
};
 
class NestedIterator {
  std::stack<NestedInteger> s;
  // [ [[[1]],1],2,[1,1] ]
  // [1,1] | 2 | 1 | [1]
    
public:
  NestedIterator(std::vector<NestedInteger> &nestedList) {
    for (auto rit = nestedList.rbegin(); rit != nestedList.rend(); ++rit) {
      s.push(*rit);
    }
  }

  int next() {
    hasNext();
    int val = s.top().getInteger();
    s.pop();
    return val;
  }

  bool hasNext() {
    while (!s.empty()) {
      if (s.top().isInteger()) return true;
      
      auto v = s.top().getList();
      s.pop();
      for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        s.push(*rit);
      }
    }
    return false;
  }
};

int main() {
  NestedInteger i1(1, {});
  NestedInteger i2(0, {i1, i1});
  NestedInteger i4(0, {i1, i1});
  NestedInteger i3(2, {});
  std::vector<NestedInteger> nList {i2, i3, i4};
  
  NestedIterator ni(nList);
  while (ni.hasNext())
    std::cout << ni.next() << ' ';
  std::cout << '\n';
}
