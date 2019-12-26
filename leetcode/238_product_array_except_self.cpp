/* Given an array nums of n integers, return an array output such that
 * output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * FIXME: solve in constant space.
 *
 * Runtime: 44 ms, faster than 44.80% of C++ online submissions.
 * Memory usage: 13.4 MB, less than 6.06% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
  int N = nums.size();
  
  std::vector<int> prodsFront (N-1, nums[0]);
  for (int i=1; i<(N-1); ++i)
    prodsFront[i] = prodsFront[i-1] * nums[i];
  
  std::vector<int> prodsBack (N-1, nums[N-1]);
  for (int i=1; i<(N-1); ++i)
    prodsBack[i] = prodsBack[i-1] * nums[N-1-i];
  
  std::vector<int> prods;
  prods.push_back(prodsBack[N-2]);
  for (int i=1; i<(N-1); ++i)
    prods.push_back(prodsFront[i-1] * prodsBack[N-2-i]);
  prods.push_back(prodsFront[N-2]);
  
  return prods;
}

int main() {
  std::vector<int> v {1,2,3,4};
  for (int i: productExceptSelf(v)) std::cout << i << ' ';
  std::cout << '\n';
}
