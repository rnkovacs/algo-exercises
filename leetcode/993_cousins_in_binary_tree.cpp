/* In a binary tree, the root node is at depth 0, and children of each depth k
 * node are at depth k+1. Two nodes of a binary tree are cousins if they have
 * the same depth, but have different parents.
 *
 * We are given the root of a binary tree with unique values, and the values
 * x and y of two different nodes in the tree. Return true if and only if the
 * nodes corresponding to the values x and y are cousins.
 *
 * Runtime: 4 ms, faster than 73.60% of C++ online submissions.
 * Memory usage: 12.4 MB, less than 6.67% of C++ online submissions.
 */

#include <iostream>
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool areSiblings(TreeNode* node, int x, int y,
                 std::unordered_map<int, int> &level, int i) {
    if (!node) return false;
    
    level[node->val] = i;
    
    if (node->left && node->right) {
        int leftVal = node->left->val;
        int rightVal = node->right->val;
        if ((leftVal == x && rightVal == y) ||
            (leftVal == y && rightVal == x))
            return true;
    }
    
    return areSiblings(node->left, x, y, level, i + 1) ||
           areSiblings(node->right, x, y, level, i + 1);
}

bool areCousins(TreeNode* root, int x, int y) {
    if (!root) return false;
    
    std::unordered_map<int, int> level;
    if (areSiblings(root, x, y, level, 0))
        return false;
    
    return level[x] == level[y];
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(5);
  std::cout << areCousins(root, 5, 4) << '\n';
}
