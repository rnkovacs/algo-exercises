/* Given a binary tree, determine if it is a valid binary search tree.
 *
 * Runtime: 12 ms, faster than 90.15% of C++ online submissions.
 * Memory usage: 19.7 MB, less than 97.92% of C++ online submissions.
 */

#include <limits>
#include <iostream>

const long LONG_MIN = std::numeric_limits<long>::min();
const long LONG_MAX = std::numeric_limits<long>::max();

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode *node, long lower, long upper) {
  if (!node) return true;
  return node->val > lower && node->val < upper &&
         isValidBST(node->left, lower, node->val) &&
         isValidBST(node->right, node->val, upper);
}

bool isValidBST(TreeNode* root) {
  return isValidBST(root, LONG_MIN, LONG_MAX);
}

int main() {
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  std::cout << isValidBST(root) << '\n';
}
