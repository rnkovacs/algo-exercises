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
 * Runtime: 104 ms, faster than 89.38% of C++ online submissions.
 * Memory usage: 36.4 MB, less than 100.00% of C++ online submissions.
 */

#include <cassert>
#include <iostream>
#include <unordered_map>

using Key = int;
using Value = int;

struct CacheData {
  Value value;
  Key pred;
  Key succ;

  CacheData() : value(-1), pred(-1), succ(-1) {}
  CacheData(int value, Key pred, Key succ)
    : value(value), pred(pred), succ(succ) {}
};

class LRUCache {
  std::unordered_map<int, CacheData> cache;
  int capacity;
  Key LRU;
  Key MRU;

public:
  LRUCache(int capacity) : capacity(capacity), LRU(-1), MRU(-1) {
    if (capacity == 0) capacity = 1;
  }

  void use(Key key) {
    if (key == MRU) return;

    if (key == LRU) {
      LRU = cache[key].succ;
      cache[LRU].pred = -1;
    }
    else {
      cache[cache[key].pred].succ = cache[key].succ;
      cache[cache[key].succ].pred = cache[key].pred;
    }

    Key oldMRU = MRU;
    cache[oldMRU].succ = key;
    MRU = key;
    cache[MRU].pred = oldMRU;
    cache[MRU].succ = -1;
  }

  Value get(Key key) {
    if (!cache.count(key)) return -1;
    use(key);
    return cache[key].value;
  }
    
  void put(Key key, Value value) {
    if (cache.count(key)) {
      cache[key].value = value;
      use(key);
      return;
    }

    if (cache.size() >= capacity) {
      Key oldLRU = LRU;
      LRU = cache[oldLRU].succ;
      if (LRU == -1) MRU = -1;
      if (LRU != -1) cache[LRU].pred = -1;
      cache.erase(oldLRU);
    }
    
    cache[key] = CacheData(value, MRU, -1);

    if (MRU == -1) {
      MRU = key;
      LRU = key;
      return;
    }

    cache[MRU].succ = key;
    MRU = key;
  }

  friend std::ostream &operator<<(std::ostream &, const LRUCache &);
};

std::ostream &operator<<(std::ostream &os, const LRUCache &c) {
  std::cout << "cache now: ";
  for (auto p : c.cache)
    std::cout << "(" << p.first << ", " << p.second.value << ") ";
  std::cout << " | LRU: " << c.LRU << " | MRU: " << c.MRU << '\n';
}

int main() {
  LRUCache cache(2);
  std::cout << "getting 2: " << cache.get(2) << '\n';
  std::cout << cache;
  cache.put(2, 6);
  std::cout << cache;
  std::cout << "getting 1: " << cache.get(1) << '\n';
  std::cout << cache;
  cache.put(1, 5);
  std::cout << cache;
  cache.put(1, 2);
  std::cout << cache;
  std::cout << "getting 1: " << cache.get(1) << '\n';
  std::cout << cache;
  std::cout << "getting 2: " << cache.get(2) << '\n';
  std::cout << cache;
}
