/* In a row of seats, 1 represents a person sitting in that seat, and 0
 * represents that the seat is empty. There is at least one empty seat, and
 * at least one person sitting. Alex wants to sit in the seat such that the
 * distance between him and the closest person to him is maximized. 
 *
 * Return that maximum distance to closest person.
 *
 * Runtime:
 * Memory usage:
 */

#include <vector>

int maxDistToClosest(std::vector<int> &seats) {
  int N = seats.size();
  
  int maxLen = 0;
  int begLen = 0;
  int endLen = 0;
  
  int start = -1;
  
  for (int i = 0; i < N; ++i) {
    if (seats[i] == 0 && start == -1)
      start = i;

    if (seats[i] == 1 && start != -1) {
      if (start == 0) begLen = i - start;
      if (maxLen < i - start) maxLen = i - start;
      start = -1;
    }
  }
  
  if (seats[N - 1] == 0) {
    endLen = N - start;
    if (maxLen <= N - start) maxLen = N - start;
  }
  
  int sideMax = std::max(begLen, endLen);
  int midMax = (maxLen + 1) / 2;
  
  return std::max(sideMax, midMax);
}
