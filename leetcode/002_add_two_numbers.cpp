/* You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Runtime: 24 ms, faster than 90.33% of C++ online submissions.
 * Memory usage: 10.2 MB, less than 92.57% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val): val(val), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
  if (!l1 && !l2) {
    if (carry) return new ListNode(carry);
    return nullptr;
  }
  
  int val = carry;
  if (l1) val += l1->val;
  if (l2) val += l2->val;
  carry = 0;

  if (val > 9) {
    carry = 1;
    val = val % 10;
  }
  
  ListNode *l3 = l1 ? l1 : l2;
  l3->val = val;
  l3->next = addTwoNumbers(l1 ? l1->next : nullptr,
                           l2 ? l2->next : nullptr,
                           carry);
  
  return l3;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  return addTwoNumbers(l1, l2, 0);
}

void printList(ListNode *head) {
  if (!head) return;

  ListNode *i = head;
  while (i) {
    std::cout << i->val << ' ';
    i = i->next;
  }
  std::cout << '\n';
}

int main() {
  ListNode *l999 = new ListNode(9);
  l999->next = new ListNode(9);
  l999->next->next = new ListNode(9);
  printList(l999);

  ListNode *l1 = new ListNode(1);
  printList(l1);

  ListNode *l1000 = addTwoNumbers(l999, l1);
  printList(l1000);
}
