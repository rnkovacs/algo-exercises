/* Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Input:
 *            1
 *             \
 *              2
 *             /
 *            3
 *
 * Output: [1, 3, 2]
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 6.8 MB, less than 100.00% of C++ online submissions.
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

std::vector<int> inorder_traversal(TreeNode *root) {
  std::vector<int> nodes;
  inorder(root, nodes);
  return nodes;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  for (int val : inorder_traversal(root1))
    std::cout << val << ' ';
  std::cout << "\n\n";
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = nullptr;
  root2->left->right = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = nullptr;
  root2->right->right = new TreeNode(3);
  for (int val : inorder_traversal(root2))
    std::cout << val << ' ';
  std::cout << "\n\n";
}
