#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
  if (!root) return root;
  TreeNode *left = invertTree(root->left);
  TreeNode *right = invertTree(root->right);
  root->left = right;
  root->right = left;
  return root;
}

void print(TreeNode *root) {
  if (!root) return;
  if (root->left) print(root->left);
  std::cout << root->val << ' ';
  if (root->right) print(root->right);
}

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right = new TreeNode(7);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  print(root);
  std::cout << '\n';
  TreeNode *root2 = invertTree(root);
  print(root2);
  std::cout << '\n';
}
