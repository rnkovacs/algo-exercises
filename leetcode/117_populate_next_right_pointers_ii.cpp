/* Given a binary tree, populate each next pointer to point to its next
 * right node. If there is no next right node, the next pointer should be
 * set to NULL. Initially, all next pointers are set to NULL.
 *
 * Runtime: 20 ms, faster than 32.28% of C++ online submissions.
 * Memory usage: 17.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
  if (!root) return root;
   
  Node *i = root;
  Node *nextRow = nullptr;
  Node *prev = nullptr;
      
  while (i) {
    while (i) {
      if (!i->left && !i->right) {
        i = i->next;
        continue;
      }
      
      if (prev) {
        if (i->left) prev->next = i->left;
        else         prev->next = i->right;
      }
      
      if (i->right) prev = i->right;
      else          prev = i->left;
      
      if (!nextRow) {
        if (i->left) nextRow = i->left;
        else         nextRow = i->right;
      }
      
      if (i->left && i->right) i->left->next = i->right;
      
      i = i->next;
    }
    i = nextRow;
    nextRow = nullptr;
    prev = nullptr;
  }
  
  return root;
}
