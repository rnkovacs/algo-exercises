/* A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 * Runtime: 4 ms, faster than 98.58% of C++ online submissions.
 * Memory usage: 12.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <unordered_map>

struct Node {
  int val;
  Node *next;
  Node *random;
  Node(int val): val(val), next(nullptr), random(nullptr) {}
};

void printList(Node *head) {
  Node *i = head;
  while (i) {
    std::cout << "(" << i->val << ", ";
    if (i->next) std::cout << i->next->val << ", ";
    else         std::cout << "null, ";
    if (i->random) std::cout << i->random->val << ") ";
    else           std::cout << "null) ";
    i = i->next;
  }
  std::cout << '\n';
}

Node *copyList(Node *node, std::unordered_map<Node*, Node *> &oldToNew) {
  if (!node) return nullptr;
  
  Node *newNode = new Node(node->val);
  newNode->next = copyList(node->next, oldToNew);
  oldToNew[node] = newNode;
  
  return newNode;
}

Node* copyRandomList(Node* head) {
  if (!head) return nullptr;
  
  std::unordered_map<Node*, Node *> oldToNew;
  Node *newHead = copyList(head, oldToNew);
  
  Node *oldI = head;
  Node *newI = newHead;
  
  while (oldI && newI) {
    newI->random = oldToNew[oldI->random];
    oldI = oldI->next;
    newI = newI->next;
  }
  
  return newHead;
}

int main() {
  Node *one = new Node(3);
  Node *two = new Node(3);
  Node *three = new Node(3);

  one->next = two;
  two->next = three;
  two->random = one;

  printList(one);
  Node *newOne = copyRandomList(one);
  printList(newOne);
}
