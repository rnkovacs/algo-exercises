/* Given a binary search tree and a node in it, find the in-order
 * successor of that node in the BST. The successor of a node p is
 * the node with the smallest key greater than p.val.
 *
 * Runtime: 40 ms, faster than 45.28% of C++ online submissions.
 * Memory usage: 23 MB, less than 100.00% of C++ online submissions.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
  if (!root) return nullptr;
  
  if (root->val > p->val) {
    // is successor if left subtree's rightmost element is p
    if (!root->left) return nullptr; // no p?
    TreeNode *i = root->left;
    while (i->right) i = i->right;
    if (i == p) return root;
    // nope, both p and its successor are in the left subtree
    return inorderSuccessor(root->left, p);
  }
  
  if (root->val == p->val) {
    // find leftmost node in right subtree
    if (!root->right) return nullptr; // no successor
    TreeNode *i = root->right;
    if (!i->left) return i;
    while (i->left) i = i->left;
    return i;
  }
  
  // if (root->val < p->val) 
  return inorderSuccessor(root->right, p);
}
