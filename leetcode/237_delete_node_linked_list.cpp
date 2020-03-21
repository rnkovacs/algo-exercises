/* Write a function to delete a node (except the tail) in a singly linked
 * list, given only access to that node.
 *
 * Runtime: 16 ms, faster than 64.84% of C++ online submissions.
 * Memory usage: 9.7 MB, less than 11.54% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val): val(val), next(nullptr) {}
};

void deleteNode(ListNode* node) {
  ListNode *nextNode = node->next;
  // node is not tail, so nextNode is never null
  // however, nextNode's next can be null
  node->val = nextNode->val;
  
  ListNode *afterNext = nextNode->next;
  delete nextNode;
  node->next = afterNext;
}

void print(ListNode *head) {
  ListNode *i = head;
  while (i) {
    std::cout << i->val << ' ';
    i = i->next;
  }
  std::cout << '\n';
}

int main() {
  ListNode *n = new ListNode(4);
  n->next = new ListNode(5);
  n->next->next = new ListNode(1);
  n->next->next->next = new ListNode(9);
  print(n);
  deleteNode(n->next);
  print(n);
}
