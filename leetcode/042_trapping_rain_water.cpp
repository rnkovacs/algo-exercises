/* Given n non-negative integers representing an elevation map where
 * the width of each bar is 1, compute how much water it is able to
 * trap after raining.
 *
 * Runtime: 4 ms, faster than 95.61% of C++ online submissions.
 * Memory usage: 8.1 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

int trap(std::vector<int> &height) {
    if (height.size() < 3) return 0;
    
    int l = 0;
    int r = height.size() - 1;
    int water = 0;
    
    int leftMax = 0;
    int rightMax = 0;
    
    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] > leftMax) leftMax = height[l];
            else                     water += leftMax - height[l];
            ++l;
        } else {
            if (height[r] > rightMax) rightMax = height[r];
            else                      water += rightMax - height[r];
            --r;
        }
    }
    
    return water;
}

int main() {
  std::vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
  std::cout << trap(height) << '\n';
}
