/* Serialization is the process of converting a data structure or object
 * into a sequence of bits so that it can be stored in a file or memory
 * buffer, or transmitted across a network connection link to be reconstructed
 * later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree.
 * There is no restriction on how your serialization/deserialization algorithm
 * should work. You just need to ensure that a binary search tree can be
 * serialized to a string and this string can be deserialized to the original
 * tree structure.
 *
 * The encoded string should be as compact as possible.
 *
 * Runtime: 52 ms, faster than 25.39% of C++ online submissions.
 * Memory usage: 29.2 MB, less than 15.38% of C++ online submissions.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  TreeNode *buildTree(std::vector<int> &postorder, int min, int max) {
    if (postorder.empty())
        return nullptr;
    
    int num = postorder.back();
    if (num < min || num > max)
        return nullptr;
    
    postorder.pop_back();
    TreeNode *node = new TreeNode(num);
    
    node->right = buildTree(postorder, num, max);
    node->left = buildTree(postorder, min, num);
        
    return node;
  }


public:    
  std::string serialize(TreeNode* node) {
    if (!node) return "";
    return serialize(node->left)
         + serialize(node->right)
         + std::to_string(node->val) + " ";
  }
  
  TreeNode* deserialize(std::string data) {
    if (data.empty()) return nullptr;
    
    std::vector<int> postorder;
    int start = 0;
    
    for (int i = 0, N = data.size(); i < N; ++i) {
      if (data[i] == ' ') {
        postorder.push_back(std::stoi(data.substr(start, i - start)));
        start = i + 1;
      }
    }
    
    return buildTree(postorder, INT_MIN, INT_MAX);
  }
};

