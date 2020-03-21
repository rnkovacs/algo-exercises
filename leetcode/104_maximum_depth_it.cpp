/* Given a binary tree, find its maximum depth.
 *
 * Example with depth = 3:
 *            3
 *           / \
 *          9  20
 *            /  \
 *           15   7
 *
 * Runtime: 4 ms, faster than 98.51% of C++ online submissions.
 * Memory usage: 18.5 MB, less than 100.00% of C++ online submissions.
 */
 
#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
  if (!root) return 0;
  
  std::stack<std::pair<TreeNode *, int>> s;
  s.push({ root, 1 });

  int maxLevel = 1;

  while (!s.empty()) {
    TreeNode *n = s.top().first;
    int level = s.top().second;
    s.pop();
    
    if (!n->left && !n->right)
      maxLevel = std::max(maxLevel, level);
    
    if (n->left) s.push({ n->left, level+1 });
    if (n->right) s.push({ n->right, level+1 });
  }
  
  return maxLevel;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  std::cout << maxDepth(root1) << '\n';
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = nullptr;
  root2->left->right = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = nullptr;
  root2->right->right = new TreeNode(3);
  std::cout << maxDepth(root2) << '\n';
}
