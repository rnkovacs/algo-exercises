/* Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * E.g. given inorder = [9,3,15,20,7] and               3
 *            postorder = [9,15,7,20,3],               / \
 *                                                    9   20
 * return the following binary tree:                     /  \
 *                                                      15  7
 *
 * Runtime: 16 ms, faster than 76.49% of C++ online submissions.
 * Memory usage: 18.3 MB, less than 38.89% of C++ online submissions.
 */


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int getInIdx(std::vector<int> &in, std::vector<int> &post, int i) {
  auto it = std::find(in.begin(), in.end(), post[i]);
  return std::distance(in.begin(), it);
}
    
TreeNode *buildTree(std::vector<int> &in, std::vector<int> &post,
                    int l, int r, int next) {
  if (l > r) return nullptr;
  TreeNode *n = new TreeNode(post[next]);
  int m = getInIdx(in, post, next);
  n->left = buildTree(in, post, l, m-1, next-(r-m)-1);
  n->right = buildTree(in, post, m+1, r, next-1);
  return n;
}
    
TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
  if (inorder.empty()) return nullptr;
  int N = inorder.size();
  return buildTree(inorder, postorder, 0, N-1, N-1);
}

int main() {
  std::vector<int> in {9,3,15,20,7};
  std::vector<int> post {9,15,7,20,3};
  TreeNode *root = buildTree(in, post);

  // Level order dump.
  std::queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *n = q.front();
    q.pop();
    std::cout << n->val << ' ';
    if (n->left) q.push(n->left);
    if (n->right) q.push(n->right);
  }
  std::cout << '\n';
}
