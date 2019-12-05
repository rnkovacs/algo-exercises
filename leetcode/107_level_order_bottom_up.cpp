/* Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values.
 *
 * Example:     3
 *            9   20
 *               15 7
 *
 * Return: [ [15, 7], [9, 20], [3] ] 
 *
 * Runtime: 8 ms, faster than 66.77% of C++ online submissions.
 * Memory usage: 13.7 MB, less than 100.00% of C++ online submissions.
 */

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
  std::vector<std::vector<int>> v;
  if (!root) return v;
  
  std::deque< std::pair<TreeNode *, int> > q;
  q.push_front({root, 1});
  
  while (!q.empty()) {
    TreeNode *n = q.front().first;
    int level = q.front().second;
    q.pop_front();
    
    if (v.size() < level) {
      std::vector<int> vv = {n->val};
      v.push_back(vv);
    } else {
      v[level-1].push_back(n->val);
    }
    
    if (n->left) q.push_back({n->left, level+1});
    if (n->right) q.push_back({n->right, level+1});
  }
  
  std::reverse(v.begin(), v.end());
  return v;
}

int main() {
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);
  
  std::vector<std::vector<int>> v = levelOrderBottom(root1);
  for (auto vv : v) {
    for (int i : vv)
      std::cout << i << ' ';
    std::cout << '\n';
  }
}
