/* For a binary tree T, we can define a flip operation as follows: choose
 * any node, and swap the left and right child subtrees.
 *
 * A binary tree X is flip equivalent to a binary tree Y if and only if we
 * can make X equal to Y after some number of flip operations.
 *
 * Write a function that determines whether two binary trees are flip
 * equivalent.  The trees are given by root nodes root1 and root2.
 *
 * Runtime: 4 ms, faster than 71.79% of C++ online submissions.
 * Memory usage: 9.5 MB, less than 100.00% of C++ online submissions.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
  if (!root1 && !root2) return true;
  if (!root1 || !root2) return false;
  if (root1->val != root2->val) return false;
  
  bool firstPair = flipEquiv(root1->left, root2->left)
                || flipEquiv(root1->left, root2->right);
  if (!firstPair) return false;
  
  bool secondPair = flipEquiv(root1->right, root2->left)
                 || flipEquiv(root1->right, root2->right);
  return secondPair;    
}
