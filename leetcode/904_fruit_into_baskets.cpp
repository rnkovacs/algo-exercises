/* In a row of trees, the i-th tree produces fruit with type tree[i]. You start
 * at any tree of your choice, then repeatedly perform the following steps:
 *
 * 1. Add one piece of fruit from this tree to your baskets. If you cannot, stop.
 * 2. Move to the next tree to the right of the current tree. If there is no
 *    tree to the right, stop.
 *
 * Note that you do not have any choice after the initial choice of starting
 * tree: you must perform step 1, then step 2, then back to step 1, then step 2,
 * and so on until you stop.
 *
 * You have two baskets, and each basket can carry any quantity of fruit, but
 * you want each basket to only carry one type of fruit each.
 *
 * What is the total amount of fruit you can collect with this procedure?
 *
 * Runtime: 116 ms, faster than 97.95% of C++ online submissions.
 * Memory usage: 14.1 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

struct Baskets {
  int one;
  int two;
  Baskets() : one(-1), two(-1) {}
  
  bool oneIsEmpty() { return one == -1 || two == -1; }
  
  bool isType(int treeType) { return one == treeType || two == treeType; }
  
  void addType(int treeType) {
    // Only after isBasket check!
    if (one == -1) one = treeType;
    else           two = treeType;
  }
  
  void eraseType(int treeType) {
    if (one == treeType) one = -1;
    else                 two = -1;
  }
};

int totalFruit(std::vector<int> &tree) {
  int N = tree.size();
  Baskets b;
  
  int l = 0;
  int r = 0;
  int maxLen = 0;

  while (b.oneIsEmpty() && r < N) {
    if (!b.isType(tree[r])) b.addType(tree[r]);
    maxLen = std::max(maxLen, ++r - l);
  }
  
  while (r < N && l < r) {
    if (b.isType(tree[r])) {
      maxLen = std::max(maxLen, ++r - l);
      continue;
    }
    for (int i = r - 2; i >= l; --i) {
      if (tree[i] != tree[r - 1]) { // r is at least 2
        b.eraseType(tree[i]);
        l = i + 1;
        break;
      }
    }
    b.addType(tree[r]);
    ++r;
  }
  
  return maxLen;
}

int main() {
  std::vector<int> trees {3,3,3,1,2,1,1,2,3,3,4};
  for (int i: trees) std::cout << i << ' ';
  std::cout << '\n' << totalFruit(trees) << '\n';
}
