/* Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Runtime: 4 ms, faster than 52.06% of C++ online submissions.
 * Memory usage: 6.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

std::vector<int> preorderTraversal(TreeNode* root) {
  if (!root) return {};
  
  std::stack<TreeNode *> st;
  st.push(root);
        
  std::vector<int> v;
  
  while (!st.empty()) {
    TreeNode *n = st.top();
    st.pop();
    v.push_back(n->val);
    
    if (n->right) st.push(n->right);
    if (n->left) st.push(n->left);
  }
  
  return v;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  for (int i: preorderTraversal(root)) std::cout << i << ' ';
  std::cout << '\n';
}
