/* Given the root of a binary tree, each node in the tree has a distinct
 * value. After deleting all nodes with a value in to_delete, we are left
 * with a forest (a disjoint union of trees).
 *
 * Return the roots of the trees in the remaining forest. You may return
 * the result in any order.
 *
 * Runtime: 32 ms, faster than 61.36% of C++ online submissions.
 * Memory usage: 21.4 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* delNode(TreeNode* node, const std::vector<int> &toDel,
                  std::vector<TreeNode*> &roots) {
  if (!node) return nullptr;
  
  node->left = delNode(node->left, toDel, roots);
  node->right = delNode(node->right, toDel, roots);
  
  if (std::binary_search(toDel.begin(), toDel.end(), node->val)) {
    if (node->left) roots.push_back(node->left);
    if (node->right) roots.push_back(node->right);
    return nullptr;
  }
  
  return node;
}
    
std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int> &toDelete) {
  if (!root) return {};
  
  std::sort(toDelete.begin(), toDelete.end());
  std::vector<TreeNode*> roots;
  
  if (!std::binary_search(toDelete.begin(), toDelete.end(), root->val))
    roots.push_back(root);
  
  delNode(root, toDelete, roots);
  
  return roots;
}

void print(TreeNode *node) {
  if (!node) return;
  std::cout << node->val << ' ';
  print(node->left);
  print(node->right);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::vector<int> toDel {3, 5};
  
  for (TreeNode *n : delNodes(root, toDel)) {
    print(n);
    std::cout << '\n';
  }
}
