/* Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.4 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

int overlap(int x1, int y1, int x2, int y2) {
    // -------   ----     ---
    //   ---       ----       ---
    std::pair<int, int> first;
    std::pair<int, int> second;

    if (x1 < x2 || (x1 == x2 && y1 < y2)) {
        first = { x1, y1 };
        second = { x2, y2 };
    } else {
        first = { x2, y2 };
        second = { x1, y1 };
    }
    
    if (second.first >= first.second)
        return 0;
    if (second.second <= first.second)
        return second.second - second.first;
    return first.second - second.first;
}
    
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int rec1area = (C - A) * (D - B);
    int rec2area = (G - E) * (H - F);
    
    if (!rec1area) return rec2area;
    if (!rec2area) return rec1area;
    
    int xOverlap = overlap(A, C, E, G);
    int yOverlap = overlap(B, D, F, H);
    
    if (!xOverlap || !yOverlap)
        return rec1area + rec2area;
    
    int overlapArea = xOverlap * yOverlap;
    return rec1area - overlapArea + rec2area;
}

int main() {
  std::cout << computeArea(-3,0,3,4,0,-1,9,2) << '\n';
}
