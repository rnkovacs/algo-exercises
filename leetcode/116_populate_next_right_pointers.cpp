/* You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. Populate each next pointer to point to
 * its next right node. If there is no next right node, the next pointer should
 * be set to NULL. Initially, all next pointers are set to NULL.
 *
 * Runtime: 24 ms, faster than 50.01% of C++ online submissions.
 * Memory usage: 16.8 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <queue>

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
  Node *prevRight = nullptr;
  
  while (i) {
    while (i) {
      if (!i->left) break;
      
      if (prevRight) prevRight->next = i->left;
      prevRight = i->right;
      
      if (!nextRow) nextRow = i->left;
      
      i->left->next = i->right;
      i = i->next;
    }
    i = nextRow;
    nextRow = nullptr;
    prevRight = nullptr;
  }
  
  return root;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right = new Node(3);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  root = connect(root);

  std::queue<Node *> q;
  Node *i = root;
  while (i) {
    q.push(i);
    i = i->left;
  }

  while (!q.empty()) {
    i = q.front();
    q.pop();

    while (i) {
      std::cout << i->val << ' ';
      i = i->next;
    }
    std::cout << '\n';
  }
}
