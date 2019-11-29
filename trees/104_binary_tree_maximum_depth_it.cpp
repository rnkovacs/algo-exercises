/* Given a binary tree, find its maximum depth.
 *
 * Example with depth = 3:
 *            3
 *           / \
 *          9  20
 *            /  \
 *           15   7
 *
 * Runtime: 8 ms, faster than 87.88% of C++ online submissions.
 * Memory usage: 18.9 MB, less than 100.00% of C++ online submissions.
 */
 
#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int max_depth(TreeNode* root) {
  if (!root) return 0;
  
  std::stack< std::pair<TreeNode *, int> > s;
  s.push({root, 1});
  
  int depth = 1;
  int max_depth = depth;
  
  while (!s.empty()) {
    TreeNode *n = s.top().first;
    depth = s.top().second;
    s.pop();
    
    if (depth > max_depth)
      max_depth = depth;
    
    TreeNode *l = n->left;
    TreeNode *r = n->right;

    if (r) s.push({r, depth+1});
    if (l) s.push({l, depth+1});
  }
  
  return max_depth;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  std::cout << max_depth(root1) << '\n';
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = nullptr;
  root2->left->right = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = nullptr;
  root2->right->right = new TreeNode(3);
  std::cout << max_depth(root2) << '\n';
}
