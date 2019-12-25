/* Given a binary tree, return the level order traversal of its nodes' values.
 *
 * Runtime: 8 ms, faster than 58.16% of C++ online submissions.
 * Memory usage: 15 MB, less than 14.08% of C++ online submissions.
 */

#include <iostream>
#include <deque>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void levelOrder(TreeNode* node, vector<vector<int>> &v, int level) {
  if (v.size() > level)
    v[level].push_back(node->val);
  else
    v.push_back({node->val});
  
  if (node->left) levelOrder(node->left, v, level + 1);
  if (node->right) levelOrder(node->right, v, level + 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};
  vector<vector<int>> levels;
  levelOrder(root, levels, 0);
  return levels;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  std::vector<std::vector<int>> v = levelOrder(root);
  for (auto vv : v) {
    for (int i : vv) std::cout << i << ' ';
    std::cout << '\n';
  }
}
