/* Implement an iterator over a binary search tree (BST). Your iterator
 * will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Runtime: 56 ms, faster than 68.95% of C++ online submissions.
 * Memory usage: 24.7 MB, less than 19.57% of C++ online submissions.
 */

#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
  std::vector<int> values;
  int nextIndex;
  
  void traverse(TreeNode *node, std::vector<int> &values) {
    if (!node) return;
    traverse(node->left, values);
    values.push_back(node->val);
    traverse(node->right, values);
  }
    
public:
  BSTIterator(TreeNode* root): nextIndex(0) {
    traverse(root, values);
  }
  
  int next() {
    return values[nextIndex++];
  }
  
  bool hasNext() {
    return nextIndex < values.size();
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
