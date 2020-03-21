/* Implement a SnapshotArray that supports the following interface:
 * - SnapshotArray(int length) initializes an array-like data structure
 *   with the given length.  Initially, each element equals 0.
 * - void set(index, val) sets the element at the given index to be equal
 *   to val.
 * - int snap() takes a snapshot of the array and returns the snap_id: the
 *   total number of times we called snap() minus 1.
 * - int get(index, snap_id) returns the value at the given index, at the
 *   time we took the snapshot with the given snap_id.
 *
 * Runtime: 280 ms, faster than 70.74% of C++ online submissions.
 * Memory usage: 84 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

class SnapshotArray {
  std::vector<std::vector<std::pair<int, int>>> snaps;
  int numSnaps;
  int length;
  
  // 0 -> {{0, 5}}
  // 1 -> {{0, 0}, {1, 6}, {3, 4}, {4, 5}}
  // 2 -> {{0, 0}, {1, 3}}
  // 3 -> {{0, 0}}
    
public:
  SnapshotArray(int length) : snaps(length), numSnaps(0), length(length) {
    for (int i = 0; i < length; ++i) snaps[i] = {{ 0, 0 }};
  }
  
  void set(int index, int val) {
    int numDiffs = snaps[index].size();
    if (snaps[index][numDiffs - 1].first == numSnaps) {
      // no snapshots since last touch
      snaps[index][numDiffs - 1].second = val;
    } else {
      snaps[index].push_back({numSnaps, val});
    }
  }
  
  int snap() { return numSnaps++; }
  
  int get(int index, int snap_id) {
    auto &v = snaps[index];
    int numDiffs = snaps[index].size();
    
    int first = 0;
    int last = numDiffs - 1;
    while (first <= last) {
      int mid = first + (last - first) / 2;
      if (v[mid].first == snap_id)
          return v[mid].second;
      if (v[mid].first < snap_id) first = mid + 1;
      else                        last = mid - 1;
    }
    
    return v[last].second;
  }
};

int main() {
  SnapshotArray a(3);
  a.set(0, 5);
  std::cout << "a[0] set to 5\n";
  a.snap();
  std::cout << "snapshot created\n";
  a.set(0, 6);
  std::cout << "a[0] set to 6\n";
  std::cout << "a[0] from snapshot 0: " << a.get(0, 0) << '\n';
}
