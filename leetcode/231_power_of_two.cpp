/* Given an integer, write a function to determine if it is a power of two.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 5.9 MB, less than 100.00% of C++ online submissions.
 */

bool isPowerOfTwo(int n) {
  if (n == 0) return false;
  if (n == INT_MIN) return false;
  return (n & (n - 1)) == 0;
}
