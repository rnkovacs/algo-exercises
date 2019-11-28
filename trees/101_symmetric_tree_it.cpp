/* Given a binary tree, check whether it is a mirror of itself (i.e. symmetric
 * around its center).
 *
 * For example, this binary tree is symmetric:
 *            1
 *          2   2
 *        3  4 4  3
 *
 * But this is not (_ is null):
 *            1
 *          2   2
 *        _  3 3  _
 *
 * Runtime: 0 ms (??), faster than 100.00% of C++ online submissions.
 * Memory usage: 15 MB, less than 32.20% of C++ online submissions.
 */

#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool is_symmetric(TreeNode *root) {
  if (!root)
    return true;

  std::stack<TreeNode *> ls;
  ls.push(root->left);
  
  std::stack<TreeNode *> rs;
  rs.push(root->right);
  
  while (!ls.empty() && !rs.empty()) {
    TreeNode *left = ls.top();
    TreeNode *right = rs.top();
      
    if (left && right && (left->val != right->val))
      return false;
    
    if ((!left && right) || (!right && left))
      return false;
    
    ls.pop();
    if (left) {
      ls.push(left->right);
      ls.push(left->left);
    }
    
    rs.pop();
    if (right) {
      rs.push(right->left);
      rs.push(right->right);
    }
  }
  
  return true;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  std::cout << is_symmetric(root1) << '\n';
  
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = nullptr;
  root2->left->right = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = nullptr;
  root2->right->right = new TreeNode(3);
  std::cout << is_symmetric(root2) << '\n';

}
