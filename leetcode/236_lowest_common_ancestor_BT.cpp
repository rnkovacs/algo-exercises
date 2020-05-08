/* Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common
 * ancestor is defined between two nodes p and q as the lowest node in T
 * that has both p and q as descendants (where we allow a node to be a
 * descendant of itself).”
 *
 * Runtime: 20 ms, faster than 73.23% of C++ online submissions.
 * Memory usage: 14.4 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool lca(TreeNode *n, TreeNode *p, TreeNode* q, TreeNode *&lcaNode) {
  if (!n) return false;
  
  bool left = lca(n->left, p, q, lcaNode);
  bool right = lca(n->right, p, q, lcaNode);
  
  if (left && right) {
    lcaNode = n;
    return true;
  }
  
  if (n == p || n == q) {
    if (left || right) lcaNode = n;
    return true;
  }
  
  return left || right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode *lcaNode = nullptr;
  lca(root, p, q, lcaNode);
  return lcaNode;
}
