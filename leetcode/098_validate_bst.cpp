/* Given a binary tree, determine if it is a valid binary search tree.
 *
 * Runtime: 12 ms, faster than 89.61% of C++ online submissions.
 * Memory usage: 20.4 MB, less than 97.92% of C++ online submissions.
 */

#include <climits>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* node, long l = LONG_MIN, long r = LONG_MAX) {
  return !node ||
         (node->val > l && node->val < r &&
          isValidBST(node->left, l, node->val) &&
          isValidBST(node->right, node->val, r));
}

int main() {
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  std::cout << isValidBST(root) << '\n';
}
