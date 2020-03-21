/* You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the
 * quality check. Since each version is developed based on the previous
 * version, all the versions after a bad version are also bad.
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.5 MB, less than 100.00% of C++ online submissions.
 */

#include <cassert>
#include <iostream>

bool isBadVersion(int version) { return version >= 4; }

int firstBadVersion(int n) {
    int first = 1;
    int last = n;
    int mid;
    
    // n = 5
    // 1, 2, 3, 4, 5
    // 0, 1, 2, 3, 4
    // g  g  g  b  b
    while (first < last) {
        mid = first + (last - first) / 2;
        
        if (isBadVersion(mid)) last = mid;
        else first = mid + 1;
    }
    
    assert(first == last && "first != last");
    return first;
}

int main() {
  std::cout << firstBadVersion(5) << '\n';
}
