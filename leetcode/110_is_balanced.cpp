/* Given a binary tree, determine if it is height-balanced.
 * In a height-balanced binary tree, the left and right subtrees of every
 * node differ in height by no more than 1.
 *
 * Runtime: 12 ms, faster than 84.37% of C++ online submissions.
 * Memory usage: 19.6 MB, less than 8.48% of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


std::pair<bool, int> is_balanced(TreeNode *node, int height) {
    if (!node) return {true, height};
    std::pair<bool, int> l = is_balanced(node->left, height + 1);
    std::pair<bool, int> r = is_balanced(node->right, height + 1);
    if (!l.first || !r.first)
        return {false, 0};
    int lh = l.second;
    int rh = r.second;
    return {abs(lh - rh) < 2, (lh > rh) ? lh : rh};
}

bool is_balanced(TreeNode* root) {
    return is_balanced(root, 0).first;
}

int main() {
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);
  std::cout << is_balanced(root1) << '\n';
  
  TreeNode *root2 = new TreeNode(1);
  root2->right = new TreeNode(2);
  root2->left = new TreeNode(2);
  root2->left->right = new TreeNode(3);
  root2->left->left = new TreeNode(3);
  root2->left->left->right = new TreeNode(4);
  root2->left->left->left = new TreeNode(4);
  std::cout << is_balanced(root2) << '\n';
}
