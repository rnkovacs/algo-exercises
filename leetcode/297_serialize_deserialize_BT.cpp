/* Serialization is the process of converting a data structure or object 
 * into a sequence of bits so that it can be stored in a file or memory
 * buffer, or transmitted across a network connection link to be
 * reconstructed later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There
 * is no restriction on how your serialization/deserialization algorithm
 * should work. You just need to ensure that a binary tree can be serialized
 * to a string and this string can be deserialized to the original tree
 * structure.
 *
 * Runtime: 100 ms, faster than 19.05% of C++ online submissions.
 * Memory usage: 311.6 MB, less than 
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::string serialize(TreeNode* root) {
  if (!root) return "()";
  
  return "(" + std::to_string(root->val)
             + serialize(root->left)
             + serialize(root->right)
       + ")";
}

TreeNode *buildTree(const std::string &data, int &i) {
  assert(data[i] == '(' && "Should be (");
  
  ++i;
  if (data[i] == ')') { ++i; return nullptr; }
  
  int numStart = i;
  while (data[++i] != '(') ;

  int val = std::stoi(data.substr(numStart, i));
  TreeNode *node = new TreeNode(val);

  node->left = buildTree(data, i);
  node->right = buildTree(data, i);

  assert(data[i] == ')' && "Should be )");
  ++i;

  return node;
}

TreeNode* deserialize(std::string data) {
  int i = 0;
  return buildTree(data, i);
}
