/* Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Runtime: 4 ms, faster than 98.90% of C++ online submissions.
 * Memory usage: 7.8 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return;
    
    std::vector<int> sortedRem;
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i; j < n; ++j) 
            sortedRem.push_back(nums[j]);
        
        std::sort(sortedRem.begin(), sortedRem.end());
        auto it = std::find(sortedRem.begin(), sortedRem.end(), nums[i]);
        
        while ((it + 1) != sortedRem.end() && *it == *(it + 1)) ++it;
        if (++it == sortedRem.end()) {
            // the element to replace is the biggest in the set
            if (i == 0) {
                nums = sortedRem;
                break;
            }
            sortedRem.clear();
            continue; // start over from one place earlier
        }
        
        // there is a bigger element in the set
        nums[i] = *it;
        sortedRem.erase(it); // remove *it from sortedRem
        
        // put the remaining elements in nums in increasing order
        for (int j = i + 1, k = 0; j < n && k < sortedRem.size(); )
            nums[j++] = sortedRem[k++];
        
        break;
    }
}

int main() {
  std::vector<int> nums {3, 2, 1};
  for (int i : nums) std::cout << i << ' '; std::cout << '\n';
  nextPermutation(nums);
  for (int i : nums) std::cout << i << ' '; std::cout << '\n';
}
