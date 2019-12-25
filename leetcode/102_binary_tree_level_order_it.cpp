/* Given a binary tree, return the level order traversal of its nodes' values.
 *
 * Runtime: 12 ms, faster than 9.77% of C++ online submissions.
 * Memory usage: 13.6 MB, less than 100.00% of C++ online submissions.
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

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  if (!root) return {};
  
  std::deque<std::pair<TreeNode *, int>> q;
  q.push_back({root, 0});
  
  std::vector<std::vector<int>> levels;
  
  while (!q.empty()) {
    TreeNode *n = q.front().first;
    int level = q.front().second;
    q.pop_front();
    
    if (levels.size() > level)
      levels[level].push_back(n->val);
    else
      levels.push_back({n->val});
    
    if (n->left) q.push_back({n->left, level + 1});
    if (n->right) q.push_back({n->right, level + 1});
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
