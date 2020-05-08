/* Given a binary tree, you need to compute the length of the diameter of
 * the tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through
 * the root.
 *
 * Runtime: 12 ms, faster than 66.22% of C++ online submissions.
 * Memory usage: 17.6 MB, less than 100.00% of C++ online submissions.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameterOfBinaryTree(TreeNode* node, int &numNodes) {
  if (!node) return 0;
  
  int leftNum = diameterOfBinaryTree(node->left, numNodes);
  int rightNum = diameterOfBinaryTree(node->right, numNodes);
  
  numNodes = std::max(numNodes, leftNum + rightNum + 1);
  return std::max(leftNum, rightNum) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
  int numNodes = 0;
  diameterOfBinaryTree(root, numNodes);
  return std::max(0, numNodes - 1);
}
