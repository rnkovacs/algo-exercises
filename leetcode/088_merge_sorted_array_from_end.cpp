/* Given two sorted integer arrays, merge the second into the first as one
 * sorted array. You may assume the first has enough space to hold additional
 * elements from the second.
 *
 * Runtime: 4 ms, faster than 85.47% of C++ online submissions.
 * Memory usage: 7.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if (m == 0) {
        nums1 = nums2;
        return;
    }
    
    int i = m - 1; // nums1
    int j = n - 1; // nums2
    int to = m + n - 1; // last free in nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[to--] = nums1[i--];
        else
            nums1[to--] = nums2[j--];
    }
    
    if (to >= 0) {
        if (j == -1) {
            while (i >= 0) nums1[to--] = nums1[i--];
        }
        if (i == -1) {
            while (j >= 0) nums1[to--] = nums2[j--];
        }
    }
}

int main() {
  std::vector<int> nums1 {1,2,3,0,0,0};
  std::vector<int> nums2 {2,5,6};
  merge(nums1, 3, nums2, 3);
  for (int i : nums1) std::cout << i << ' ';
  std::cout << '\n';
}
