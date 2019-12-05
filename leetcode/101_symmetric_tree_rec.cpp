/* Given a binary tree, check whether it is a mirror of itself (i.e. symmetric
 * around its center).
 *
 * For example, this binary tree is symmetric:
 *            1
 *          2   2
 *        3  4 4  3
 *
 * But this is not (_ is null):
 *            1
 *          2   2
 *        _  3 3  _
 *
 * Runtime: 4 ms, faster than 84.29% of C++ online submissions.
 * Memory usage: 14.6 MB, less than 96.61% of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool is_symmetric(TreeNode *root1, TreeNode *root2) {
  if (!root1 && !root2)
    return true;
  
  if (!root1 || !root2)
    return false;
  
  return (root1->val == root2->val) &&
         is_symmetric(root1->left, root2->right) &&
         is_symmetric(root1->right, root2->left);
}

bool is_symmetric(TreeNode *root) {
  return is_symmetric(root, root);
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  std::cout << is_symmetric(root1) << '\n';
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = nullptr;
  root2->left->right = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = nullptr;
  root2->right->right = new TreeNode(3);
  std::cout << is_symmetric(root2) << '\n';

}
