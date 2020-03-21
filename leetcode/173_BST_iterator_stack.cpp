/* Implement an iterator over a binary search tree (BST). Your iterator
 * will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Runtime: 56 ms, faster than 68.95% of C++ online submissions.
 * Memory usage: 23.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
  std::stack<TreeNode *> st;
  
  void goToLeftmost(TreeNode *node) {
    if (!node) return;
    st.push(node);
    while (node->left) {
      st.push(node->left);
      node = node->left;
    }
  }
    
public:
  BSTIterator(TreeNode* root) {
    goToLeftmost(root);
  }
  
  int next() {
    TreeNode *n = st.top();
    st.pop();
    if (n->right)
      goToLeftmost(n->right);
    return n->val;
  }
  
  bool hasNext() {
    return !st.empty();
  }
};

int main() {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator *it = new BSTIterator(root);
  std::cout << it->next() << '\n';
  std::cout << it->next() << '\n';
  std::cout << "hasNext: " << it->hasNext() << '\n';
  std::cout << it->next() << '\n';
  std::cout << "hasNext: " << it->hasNext() << '\n';
  std::cout << it->next() << '\n';
  std::cout << "hasNext: " << it->hasNext() << '\n';
  std::cout << it->next() << '\n';
  std::cout << "hasNext: " << it->hasNext() << '\n';
}
