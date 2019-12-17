/* Given two binary trees, write a function to check if they are the same.
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 *
 * Input:      1        1
 *            / \      / \
 *           2   3    2   3
 * Output: true
 *
 * Input:      1        1
 *            /          \
 *           2            2
 * Output: false
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 9.7 MB, less than 100.00% (?) of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool is_same(TreeNode *p, TreeNode *q) {
  if (!p && !q) return true;
  if (!p || !q) return false;
  return (p->val == q->val) &&
          is_same(p->left, q->left) &&
          is_same(p->right, q->right);
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);

  std::cout << is_same(root1, root2) << '\n';

  root1 = new TreeNode(1);
  root1->left = new TreeNode(2);

  root2 = new TreeNode(1);
  root2->right = new TreeNode(2);
  
  std::cout << is_same(root1, root2) << '\n';
}
