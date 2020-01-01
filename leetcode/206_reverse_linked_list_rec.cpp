/* Reverse a singly linked list.
 *
 * Runtime: 4 ms, faster than 99.02% of C++ online submissions.
 * Memory usage: 9.2 MB, less than 89.31% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
  if (!head || !head->next) return head;
  
  ListNode *newHead = reverseList(head->next);
  
  head->next->next = head;
  head->next = nullptr;
  
  return newHead;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  
  ListNode *i = head;
  while (i) { std::cout << i->val << ' ', i = i->next; }
  std::cout << '\n';

  ListNode *newHead = reverseList(head);
  
  i = newHead;
  while (i) { std::cout << i->val << ' ', i = i->next; }
  std::cout << '\n';
}
