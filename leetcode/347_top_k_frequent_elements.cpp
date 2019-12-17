/* Given a non-empty array of integers, return the k most frequent elements.
 *
 * Runtime: 20 ms, faster than 81.15% of C++ online submissions.
 * Memory usage: 11.4 MB, less than 96.77% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using Element = int;
using Freq = int;
using ElemFreq = std::pair<Element, Freq>;

struct ElemComp {
  bool operator()(const ElemFreq &e1, const ElemFreq &e2) {
    return e1.second < e2.second;
  }
};

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    if (nums.size() == 1) return { nums[0] };
    
    std::unordered_map<Element, Freq> m;
    for (int num : nums)
        m[num]++;
    
    std::priority_queue<ElemFreq, std::vector<ElemFreq>, ElemComp> q;
    for (auto entry : m)
        q.push({entry.first, entry.second});

    std::vector<int> topK;
    for (int i=0; i<k; ++i) {
        topK.push_back(q.top().first);
        q.pop();
    }
    return topK;
}

int main() {
  std::vector<int> nums {1,1,1,2,2,3};
  for (int i : nums) std::cout << i << ' ';
  std::cout << "\n2 most frequent: ";
  for (int i : topKFrequent(nums, 2)) std::cout << i << ' ';
  std::cout << '\n';
}
