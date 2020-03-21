/* Given an array where elements are sorted in ascending order, convert it
 * to a height-balanced BST. In a height-balanced tree the depth of the two 
 * subtrees of every node never differ by more than 1.
 *
 * Runtime: 16 ms, faster than 99.28% of C++ online submissions.
 * Memory usage: 24 MB, less than 24.32% of C++ online submissions.
 */

#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(std::vector<int> &nums, int l, int r) {
    if (r < l) return nullptr;
    int m = (r - l) / 2 + l;
    TreeNode *node = new TreeNode(nums[m]);
    node->left = buildTree(nums, l, m-1);
    node->right = buildTree(nums, m+1, r);
    return node;
}

TreeNode* sortedArrayToBST(std::vector<int> &nums) {
    if (nums.empty()) return nullptr;
    return buildTree(nums, 0, nums.size()-1);
}

void print(TreeNode *node) {
  if (!node) return;
  print(node->left);
  std::cout << node->val << ' ';
  print(node->right);
}

int main() {
  std::vector<int> v {-10, -3, 0, 5, 9};
  for (int i : v) std::cout << i << ' ';
  std::cout << '\n';
  print(sortedArrayToBST(v));
  std::cout << '\n';
}
