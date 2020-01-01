/* Given a BST, find the lowest common ancestor of two given nodes.
 *
 * Runtime: 32 ms, faster than 94.83% of C++ online submissions.
 * Memory usage: 25.7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) return nullptr;
  
  // One of the values is this root (we're going from top to bottom).
  if (root == p || root == q) return root;
  
  bool pLeft = p->val < root->val;
  bool qLeft = q->val < root->val;
  
  // The two values are in different subtrees.
  if (pLeft && !qLeft || !pLeft && qLeft) return root;
  
  // Both values are in the left subtree.
  if (pLeft && qLeft) return lowestCommonAncestor(root->left, p, q);
  
  // Both values are in the right subtree.
  return lowestCommonAncestor(root->right, p, q);
}

int main() {
  TreeNode *root = new TreeNode(6);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n8 = new TreeNode(8);
  root->left = n2;
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  root->right = n8;
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  std::cout << lowestCommonAncestor(root, n2, n8)->val << '\n';
}
