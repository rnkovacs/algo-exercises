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
    int i = 0; // index of element in nums1 being checked
    int j = 0; // index of element in nums2 being checked
    int end = m; // index of first "free" spot in nums1

    while (i < (m + n) && j < n) {
        if (nums1[i] <= nums2[j] && i < end) ++i;
        else {
            // from i until end, copy elements one place to the right
            for (int k = end - 1; k >= i; --k)
                nums1[k + 1] = nums1[k];
            ++end;
            nums1[i++] = nums2[j++];
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
