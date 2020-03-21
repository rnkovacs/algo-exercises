/* Given a binary tree, return the zigzag level order traversal of its
 * nodes' values. (ie, from left to right, then right to left for the next
 * level and alternate between).
 *
 * Runtime: 4 ms, faster than 85.53% of C++ online submissions.
 * Memory usage: 11.1 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
  if (!root) return {};
  
  std::queue<std::pair<TreeNode *, int>> q;
  q.push({ root, 0 });
  
  std::vector<std::vector<int>> v;
  
  while (!q.empty()) {
    TreeNode *n = q.front().first;
    int level = q.front().second;
    q.pop();
    
    if (level == v.size()) v.push_back({ n->val });
    else v[level].push_back({ n->val });
    
    if (n->left) q.push({ n->left, level + 1 });
    if (n->right) q.push({ n->right, level + 1 });
  }
  
  for (int i = 1; i < v.size(); i += 2)
    std::reverse(v[i].begin(), v[i].end());
  
  return v;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  for (auto &v: zigzagLevelOrder(root)) {
    for (int i: v) std::cout << i << ' ';
    std::cout << '\n';
  }
}
