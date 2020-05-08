/* Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Runtime: 20 ms, faster than 72.43% of C++ online submissions.
 * Memory usage: 17.9 MB, less than 38.10% of C++ online submissions.
 */

#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const std::vector<int> &preorder,
                    const std::unordered_map<int, int> &inorder,
                    int &pNext, int iLeft, int iRight) {
    
  if (pNext == preorder.size() || iLeft > iRight)
    return nullptr;
  
  TreeNode *node = new TreeNode(preorder[pNext]);
  int iMid = inorder.at(node->val);
  
  if (iLeft < iMid)
    node->left = buildTree(preorder, inorder, ++pNext, iLeft, iMid - 1);
  
  if (iMid < iRight)
    node->right = buildTree(preorder, inorder, ++pNext, iMid + 1, iRight);
  
  return node;
}
    
TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
  int N = preorder.size();
  std::unordered_map<int, int> ioMap;
  
  for (int i = 0; i < N; ++i)
    ioMap.insert({ inorder[i], i });
  
  int pNext = 0;
  return buildTree(preorder, ioMap, pNext, 0, N - 1);
}
