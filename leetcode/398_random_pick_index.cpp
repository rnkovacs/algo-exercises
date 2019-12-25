/* Given an array of integers with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array.
 *
 * Runtime: 92 ms, faster than 66.77% of C++ online submissions.
 * Memory usage: 19 MB, less than 90.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

std::random_device rd;
std::mt19937 gen(rd());

int pick(std::vector<int> &nums, int target) {
  auto begin = nums.begin();
  auto end = nums.end();
 
  std::uniform_real_distribution<double> dist(0.0, 1.0);
  int pickedIndex = 0;
  int currentIndex = 0;
  int count = 0;
  
  auto it = std::find(begin, end, target);
  while (it != end) {
    currentIndex = std::distance(begin, it);
    count++;
    if (dist(gen) < (double)1 / count)
      pickedIndex = currentIndex;
    it = std::find(++it, end, target);
  }

  return pickedIndex;
}

int main() {
  std::vector<int> v {4,-3,9,11,-3,4,5,-3,77};
  std::cout << pick(v, -3) << '\n';
  std::cout << pick(v, -3) << '\n';
  std::cout << pick(v, -3) << '\n';
  std::cout << pick(v, -3) << '\n';
}
