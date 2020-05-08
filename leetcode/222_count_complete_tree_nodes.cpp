/* Given a complete binary tree, count the number of nodes.
 *
 * Runtime: 36 ms, faster than 48.68% of C++ online submissions.
 * Memory usage: 26.5 MB, less than 100.00% of C++ online submissions.
 */

bool exists(TreeNode* i, int num, int l, int r) {        
  while (l < r) {
    int m = l + (r - l + 1) / 2;
    if (num >= m) {
      i = i->right;
      l = m;
    } else {
      i = i->left;
      r = m - 1;
    }
  }
  return i;
}
    
int countNodes(TreeNode* root) {
  if (!root) return 0;
  
  TreeNode *i = root;
  int count = 1;
  int level = 1;
  
  while (i->right) {
    i = i->right;
    count += std::pow(2, level);
    ++level;
  }

  int left = count + 1;
  int right = count + std::pow(2, level);

  if (!exists(root, count + 1, left, right))
      return count;
  
  i = root;
  while (left < right) {
    int mid = left + (right - left + 1) / 2;
    
    if (exists(i, mid, left, right)) {
      // this may or may not be the last node in the row
      left = mid;
      i = i->right;
    } else {
      // the last node in the row is to the left
      right = mid - 1;
      i = i->left;
    }
    
    if (left == right) return left;
  }
  
  return count;
}
