/* Given a BST, write a function to find the kth smallest element in it.
 *
 * Runtime: 20 ms, faster than 82.95% of C++ online submissions.
 * Memory usage: 21.8 MB, less than 26.67% of C++ online submissions.
 */

#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *node, std::vector<int> &v) {
  if (!node) return;
  inorder(node->left, v);
  v.push_back(node->val);
  inorder(node->right, v);
}

int kthSmallest(TreeNode* root, int k) {
  if (!root) return 0;
  std::vector<int> v;
  inorder(root, v);
  return v[k-1];
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->left->right = new TreeNode(2);
  root->right = new TreeNode(4);

  std::cout << kthSmallest(root, 1) << '\n';
}
