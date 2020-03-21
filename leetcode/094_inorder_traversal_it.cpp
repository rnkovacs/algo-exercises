/* Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Input:
 *            1
 *             \
 *              2
 *             /
 *            3
 *
 * Output: [1, 3, 2]
 *
 * Runtime: 4 ms, faster than 51.49% of C++ online submissions.
 * Memory usage: 7 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
  if (!root) return {};

  std::stack<TreeNode *> st;
  st.push(root);
  
  TreeNode *i = root->left;
  while (i) {
    st.push(i);
    i = i->left;
  }
  
  std::vector<int> v;
  while (!st.empty()) {
    TreeNode *n = st.top();
    st.pop();
    v.push_back(n->val);
    
    if (!n->right) continue;
    
    i = n->right;
    while (i) {
      st.push(i);
      i = i->left;
    }
  }
  return v;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right = new TreeNode(2);
  root1->right->left = new TreeNode(4);
  root1->right->right = new TreeNode(3);
  for (int val : inorderTraversal(root1))
    std::cout << val << ' ';
  std::cout << "\n\n";

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = nullptr;
  root2->left->right = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = nullptr;
  root2->right->right = new TreeNode(3);
  for (int val : inorderTraversal(root2))
    std::cout << val << ' ';
  std::cout << "\n\n";
}
