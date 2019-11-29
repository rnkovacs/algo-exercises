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
 * Memory usage: 19.1 MB, less than 98.90% of C++ online submissions.
 */
 
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int count_depth(TreeNode *n, int counter) {
    if (!n) return counter;
    ++counter;
    int l = count_depth(n->left, counter);
    int r = count_depth(n->right, counter);
    return (l > r) ? l : r;
}

int max_depth(TreeNode* root) {
    return count_depth(root, 0);
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
