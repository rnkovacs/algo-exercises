/* Given a non-empty binary tree, find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through
 * the root.
 *
 * E.g.     1
 *        2   3      Output: 6
 *
 * Runtime: 28 ms, faster than 85.26% of C++ online submissions.
 * Memory usage: 24.7 MB, less than 60.61% of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSum(TreeNode *node, int &maxSum) {
  if (!node) return 0;
  
  int leftSum = maxPathSum(node->left, maxSum);
  int rightSum = maxPathSum(node->right, maxSum);
  
  maxSum = std::max(maxSum, leftSum + rightSum + node->val);
  return std::max(0, std::max(leftSum, rightSum) + node->val);
}

int maxPathSum(TreeNode* root) {
  int maxSum = (root) ? root->val : 0;
  maxPathSum(root, maxSum);
  return maxSum;
}

int main() {
  TreeNode *root = new TreeNode(-10);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  std::cout << maxPathSum(root) << '\n';
}
