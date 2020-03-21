/* Write a program to find the node at which the intersection of two linked lists
 * begins.
 *
 * Runtime: 52 ms, faster than 62.87% of C++ online submissions.
 * Memory usage: 15.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val): val(val), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int lenA = 0;
  ListNode *i = headA;
  while (i) { ++lenA; i = i->next; }
  
  int lenB = 0;
  i = headB;
  while (i) { ++lenB; i = i->next; }
  
  ListNode *ii;
  if (lenA > lenB) {
    i = headA;
    ii = headB;
    while (lenA > lenB) { i = i->next; --lenA; }
  } else {
    i = headB;
    ii = headA;
    while (lenB > lenA) { i = i->next; --lenB; }
  }
  
  while (i && ii) {
    if (i == ii) return i;
    i = i->next;
    ii = ii->next;
  }
  
  return nullptr;
}

int main() {
  ListNode *one = new ListNode(9);
  one->next = new ListNode(1);
  ListNode *two = new ListNode(3);

  ListNode *intersec = new ListNode(2);
  intersec->next = new ListNode(4);

  one->next = intersec;
  two->next = intersec;

  ListNode *node = getIntersectionNode(one, two);
  std::cout << (node == intersec) << '\n';
}
