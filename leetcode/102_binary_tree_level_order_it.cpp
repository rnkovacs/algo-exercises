/* Given a binary tree, return the level order traversal of its nodes' values.
 *
 * Runtime: 4 ms, faster than 93.41% of C++ online submissions.
 * Memory usage: 13.1 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};
  
  std::vector<std::vector<int>> levels;

  std::queue<std::pair<TreeNode *, int>> q;
  q.push({root, 0});
  
  while (!q.empty()) {
    TreeNode *n = q.front().first;
    int level = q.front().second;
    q.pop();
    
    if (level == levels.size())
      levels.push_back({});

    levels[level].push_back(n->val);
    
    if (n->left) q.push({n->left, level + 1});
    if (n->right) q.push({n->right, level + 1});
  }
  
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
