/* Design and implement a data structure for LRU cache. It should support
 * the following operations: get and put.
 *
 *   get(key) - Get the value (will always be positive) of the key if the
 *              key exists in the cache, otherwise return -1.
 *   put(key, value) - Set or insert the value if the key is not already
 *                     present. When the cache reached its capacity, it
 *                     should invalidate the least recently used item before
 *                     inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Runtime: 116 ms, faster than 55.54% of C++ online submissions.
 * Memory usage: 39.2 MB, less than 54.88% of C++ online submissions.
 */

#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
  using Key = int;
  using Value = int;
  using ListIt = std::list<Key>::iterator;
  
  std::unordered_map<Key, std::pair<Value, std::list<Key>::iterator>> dict;
  std::list<Key> keys;
  // front : MRU .... LRU : back
  int capacity;
  
  void use(Key key) {
    ListIt it = dict[key].second;
    keys.erase(it);
    keys.push_front(key);
    dict[key].second = keys.begin();
  }

public:
  LRUCache(int capacity) : capacity(capacity) {}
  
  int get(Key key) {
    if (dict.find(key) == dict.end()) return -1;
    
    use(key);
    return dict[key].first;
  }

  void put(Key key, Value value) {
    // Key already in map, no need to worry about capacity.
    if (dict.find(key) != dict.end()) {
      use(key);
      dict[key].first = value;
      return;
    }
    
    // If capacity is reached, evict LRU entry.
    if (keys.size() == capacity) {
      dict.erase(keys.back());
      keys.pop_back();
    }
    
    // Put new entry in map.
    keys.push_front(key);
    dict[key] = { value, keys.begin() };
  }
};

int main() {
  LRUCache cache(2);
  std::cout << "capacity: 2\n";
  std::cout << "getting 2: " << cache.get(2) << '\n';
  cache.put(2, 6);
  std::cout << "putting (2, 6)\n";
  std::cout << "getting 1: " << cache.get(1) << '\n';
  cache.put(1, 5);
  std::cout << "putting (1, 5)\n";
  cache.put(1, 2);
  std::cout << "putting (1, 2)\n";
  std::cout << "getting 1: " << cache.get(1) << '\n';
  std::cout << "getting 2: " << cache.get(2) << '\n';
}
