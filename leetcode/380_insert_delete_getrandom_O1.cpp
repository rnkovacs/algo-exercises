/* Design a data structure that supports all following operations in
 * average O(1) time.
 *
 * 1. insert(val): Inserts an item val to the set if not already present.
 * 2. remove(val): Removes an item val from the set if present.
 * 3. getRandom: Returns a random element from current set of elements. Each
 *               element must have the same probability of being returned.
 *
 * Runtime: 56 ms, faster than 65.66% of C++ online submissions.
 * Memory usage: 21.6 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

class RandomizedSet {
  std::unordered_map<int, int> m;
  std::vector<int> v;
  std::random_device rd;
  std::mt19937 gen;
    
public:
  RandomizedSet(): rd(), gen(rd()) {}
  
  bool insert(int val) {
    if (m.find(val) != m.end()) return false;
    
    v.push_back(val);
    m.insert({ val, v.size() - 1 });
    return true;
  }
  
  bool remove(int val) {
    if (m.find(val) == m.end()) return false;
    
    // Last element gets the index of the one to be removed.
    m[v[v.size() - 1]] = m[val];
    // Move it to its place in the vector.
    std::swap(v[m[val]], v[v.size() - 1]);
    v.pop_back();
    m.erase(val);
    return true;
  }
  
  int getRandom() {
    std::uniform_int_distribution<> dis(0, v.size() - 1);
    return v[dis(gen)];
  }
};

int main() {
  RandomizedSet r;
  std::cout << "inserted 1: " << r.insert(1) << '\n';
  std::cout << "removed 2: " << r.remove(2) << '\n';
  std::cout << "inserted 2: " << r.insert(2) << '\n';
  std::cout << "getRandom: " << r.getRandom() << '\n';
  std::cout << "removed 1: " << r.remove(1) << '\n';
  std::cout << "inserted 2: " << r.insert(2) << '\n';
  std::cout << "getRandom: " << r.getRandom() << '\n';
}
