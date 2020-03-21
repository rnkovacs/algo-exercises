/* Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.1 MB, less than 100.00% of C++ online submissions.
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

void collect(std::stack<std::pair<TreeNode *, bool>> &st, TreeNode *n) {
  TreeNode *i = n;
  while (i) {
    while (i->left) {
      if (i->right) st.push({ i->right, false });
      st.push({ i->left, true });
      i = i->left;
    }
    i = i->right;
    if (i) st.push({ i, true });
  }
}

std::vector<int> postorderTraversal(TreeNode* root) {
  if (!root) return {};

  std::stack<std::pair<TreeNode *, bool>> st;
  st.push({ root, true });
  collect(st, root);
  
  std::vector<int> v;
  
  while (!st.empty()) {
    TreeNode *n = st.top().first;
    bool OKtoVisit = st.top().second;
    st.pop();
    
    if (OKtoVisit) {
      v.push_back(n->val);
      continue;
    }
    
    st.push({ n, true });
    collect(st, n);
  }
  
  return v;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  for (int i: postorderTraversal(root)) std::cout << i << ' ';
  std::cout << '\n';
}
