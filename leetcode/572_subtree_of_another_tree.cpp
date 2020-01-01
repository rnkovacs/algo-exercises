/* Given two non-empty binary trees s and t, check whether t has exactly the
 * same structure and node values than a subtree of s.
 *
 * Runtime: 28 ms, faster than 77.07% of C++ online submissions.
 * Memory usage: 20.9 MB, less than 87.50% of C++ online submissions.
 */

#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode *s, TreeNode *t) {
  if (!s && !t) return true;
  if (!s || !t) return false;
  return s->val == t->val &&
         isSameTree(s->left, t->left) &&
         isSameTree(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
  if (!s && !t) return true;
  if (!s) return false;
  return isSameTree(s, t) ||
         isSubtree(s->left, t) ||
         isSubtree(s->right, t);
}

int main() {
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(4);
  root1->left->left = new TreeNode(1);
  root1->left->right = new TreeNode(2);
  root1->right = new TreeNode(5);

  TreeNode *root2 = new TreeNode(4);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(2);

  std::cout << isSubtree(root1, root2) << '\n';
}
