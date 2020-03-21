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
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 13.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetric(TreeNode *node1, TreeNode *node2) {
  if (!node1 && !node2) return true;
  if (!node1 || !node2) return false;
  return node1->val == node2->val &&
         isSymmetric(node1->left, node2->right) &&
         isSymmetric(node1->right, node2->left);
} 

bool isSymmetric(TreeNode *root) {
  if (!root) return true;
  return isSymmetric(root->left, root->right);
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  std::cout << isSymmetric(root1) << '\n';
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = nullptr;
  root2->left->right = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = nullptr;
  root2->right->right = new TreeNode(3);
  std::cout << isSymmetric(root2) << '\n';

}
