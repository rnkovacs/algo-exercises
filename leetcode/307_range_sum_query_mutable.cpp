/* Given an integer array nums, find the sum of the elements between indices
 * i and j (i ≤ j), inclusive. The update(i, val) function modifies nums by
 * updating the element at index i to val.
 *
 * Runtime: 44 ms, faster than 53.73% of C++ online submissions.
 * Memory usage: 17.1 MB, less than 100.00% of C++ online submissions.
 */

class NumArray {
  int n;
  int N;
  std::vector<int> tree;
  
  // 1 3 5 -> 2 * 3 = 6 -> 8
  // 0 9 4 5 1 3 5 0
  // 0 1 2 3 4 5 6 7
  
  //       9
  //    4      5
  //  1   3  5   0
  
  void buildTree(std::vector<int> &nums) {
    for (int i = N / 2, j = 0; j < n; ++i, ++j)
      tree[i] = nums[j];
    
    for (int i = N / 2 - 1; i > 0; --i)
      tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
    
public:
  NumArray(std::vector<int> &nums) : n(nums.size()), tree(2 * n, 0) {
    if (n == 0) return;
    
    int M = 2 * n;
    // if 2 * n is not power of 2, make it one
    if ((M & (M - 1)) != 0) {
      int i = std::ceil(std::log2(M));
      N = std::pow(2, i);
    }
    else N = M;
    
    tree.resize(N);
    buildTree(nums);
  }
    
  void update(int i, int val) {
    int pos = i + N / 2;
    
    int diff = val - tree[pos];
    tree[pos] = val;
    pos /= 2;
    
    while (pos > 0) {
      tree[pos] += diff;
      pos /= 2;
    }
  }

  int sumRange(int i, int j) {
    int l = N / 2 + i;
    int r = N / 2 + j;
    
    if (l > r) return 0;
    if (l == r) return tree[l];
    
    int S = 0;
    while (l <= r) {
      if (l % 2) S += tree[l++]; // l is now even
      l = l / 2;

      if (!(r % 2)) S += tree[r--]; // r is now odd
      r = r / 2;
    }
    return S;
  }
};
