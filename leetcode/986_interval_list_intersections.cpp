/* Given two lists of closed intervals, each list of intervals pairwise
 * disjoint and in sorted order, return the intersection of the two lists.
 *
 * Runtime: 52 ms, faster than 77.32% of C++ online submissions.
 * Memory usage: 15.7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

using Interval = std::vector<int>;
using IntervalList = std::vector<Interval>;

bool checkIntersect(const Interval &a, const Interval &b) {
  const Interval &sm = (a[0] < b[0]) ? a : b;
  const Interval &la = (a[0] > b[0]) ? a : b;
  return la[0] <= sm[1];
}
    
int hasLargerEnd(const Interval &a, const Interval &b) {
  return (a[1] > b[1]) ? 0 : 1;
}

void doIntersect(IntervalList &C, const Interval &a, const Interval &b) {
  C.push_back({ std::max(a[0], b[0]), std::min(a[1], b[1]) });
}

IntervalList intervalIntersection(IntervalList &A, IntervalList &B) {
  if (A.empty()) return {};
  if (B.empty()) return {};
    
  auto i = A.begin();
  auto j = B.begin();
  auto iend = A.end();
  auto jend = B.end();
    
  IntervalList C;
  int largest;
    
  while (i != iend && j != jend) {
    if (checkIntersect(*i, *j))
      doIntersect(C, *i, *j);
    largest = hasLargerEnd(*i, *j);
    if (largest == 0) j++;
    else              i++;
  }
  
  return C;
}

void print(const IntervalList &A) {
  for (Interval I : A)
    std::cout << "[" << I[0] << ", " << I[1] << "], "; 
  std::cout << '\n';
}

int main() {
  IntervalList A { {0,2}, {5,10}, {13,23}, {24,25} };
  IntervalList B { {1,5}, {8,12}, {15,24}, {25,26} };
  std::cout << "A : ";
  print(A);
  std::cout << "B : ";
  print(B);
  std::cout << "Intersection : ";
  print(intervalIntersection(A, B));
  std::cout << '\n';
  
  IntervalList C { {1,3}, {4,5} };
  IntervalList D {};
  std::cout << "C : ";
  print(C);
  std::cout << "D : ";
  print(D);
  std::cout << "Intersection : ";
  print(intervalIntersection(C, D));
}
