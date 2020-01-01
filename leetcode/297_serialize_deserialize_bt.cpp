/* Design an algorithm to serialize and deserialize a binary tree.
 *
 * Runtime: 40 ms, faster than 64.96% of C++ online submissions.
 * Memory usage: 25.5 MB, less than 93.10% of C++ online submissions.
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::string serialize(TreeNode* root) {
  std::string s;
  std::queue<TreeNode *> q;
  q.push(root);
  
  while (!q.empty()) {
    TreeNode *n = q.front();
    q.pop();
    
    if (!n) {
      s += "null ";
      continue;
    }

    s += std::to_string(n->val);
    s += " ";
    q.push(n->left);
    q.push(n->right);
  }

  return s;
}

TreeNode* deserialize(std::string data) {
  std::stringstream ss(data);
  std::string current;
  std::vector<TreeNode *> v;
  
  while (ss >> current) {
    TreeNode *n = nullptr;
    if (current != "null") {
      int val = std::atoi(current.c_str());
      n = new TreeNode(val);
    }
    v.push_back(n);
  }
  
  int skip = 0;
  for (int i=0, s=v.size(); i<s; ++i) {
    if (!v[i]) {
      skip++;
      continue;
    }
    int base = 2 * i - 2 * skip;
    if (base + 1 < s) v[i]->left = v[base + 1];
    if (base + 2 < s) v[i]->right = v[base + 2];
  }
  
  return v[0];
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  std::cout << serialize(root) << '\n';

  std::string s = "1 2 3 null null 4 5 ";
  std::cout << serialize(deserialize(s)) << '\n';
}
