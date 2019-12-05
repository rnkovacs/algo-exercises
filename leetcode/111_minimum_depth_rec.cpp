/* Given a binary tree, find its minimum depth.
 *
 * Example with minimum depth = 2:
 *            3
 *           / \
 *          9  20
 *            /  \
 *           15   7
 *
 * Runtime: 12 ms, faster than 76.06% of C++ online submissions.
 * Memory usage: 19.5 MB, less than 92.86% of C++ online submissions.
 */
 
#include <limits>
#include <iostream>

const int int_max = std::numeric_limits<int>::max();

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int count_depth(TreeNode* n, int count) {
  if (!n->left && !n->right)
    return count;
  
  int lc = (n->left) ? count_depth(n->left, count+1) : int_max;
  int rc = (n->right) ? count_depth(n->right, count+1) : int_max;
  return (lc < rc) ? lc : rc;
}

int min_depth(TreeNode* root) {
  if (!root) return 0;
  return count_depth(root, 1);
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  std::cout << min_depth(root1) << '\n';
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = nullptr;
  std::cout << min_depth(root2) << '\n';
}
