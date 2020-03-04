/* Given two arrays, write a function to compute their intersection.
 *
 * Runtime: 8 ms, faster than 75.43% of C++ online submissions.
 * Memory usage: 8.4 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    int N = nums1.size();
    int M = nums2.size();
    if (N == 0 || M == 0) return {};
    
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    
    std::vector<int> common;
    
    for (int i=0, j=0; i<N, j<M;  ) {
        if (nums1[i] == nums2[j]) {
            common.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    return common;
}

int main() {
  std::vector<int> n1 {4, 9, 5};
  std::vector<int> n2 {9, 4, 9, 8, 4};
  for (int i : intersect(n1, n2))
    std::cout << i << ' ';
  std::cout << '\n';
}
