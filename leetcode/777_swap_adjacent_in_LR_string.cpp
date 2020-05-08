/* In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL",
 * a move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". Given the starting string start
 * and the ending string end, return True if and only if there exists a
 * sequence of moves to transform one string to the other.
 *
 * Runtime: 8 ms, faster than 94.04% of C++ online submissions.
 * Memory usage: 7.5 MB, less than 100.00% of C++ online submissions.
 */

bool canTransform(std::string start, std::string end) {
  int N = start.size();
  int i = 0;
  int j = 0;
  
  while (i < N && j < N) {
    if (start[i] == 'X') { ++i; continue; }
    if (end[j]   == 'X') { ++j; continue; }
    
    if ( start[i] != end[j]
     || (start[i] == 'L' && i < j)
     || (start[i] == 'R' && i > j)) {
      return false;
    }
    
    ++i; ++j;
  }
  
  if (i == N && j != N) {
    for ( ; j < N; ++j) {
      if (end[j] != 'X') return false;
    }
  }
  
  if (j == N && i != N) {
    for ( ; i < N; ++i) {
      if (start[i] != 'X') return false;
    }
  }
  
  return true;
}
