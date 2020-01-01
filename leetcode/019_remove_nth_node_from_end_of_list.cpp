/* Given a linked list, remove the nth node from the end of the list
 * and return its head..
 *
 * Runtime: 4 ms, faster than 86.53% of C++ online submissions.
 * Memory usage: 8.5 MB, less than 86.84% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (!head) return nullptr;
  
  ListNode *i = head;
  ListNode *ii = head;
  
  while (n > 0 && i) {
    i = i->next;
    n--;
  }
  
  // List has fewer elements than n.
  if (n > 0) return head;
  
  // List has exactly n elements.
  if (!i) {
    ListNode *oldHead = head;
    head = head->next;
    delete oldHead;
    return head;
  }

  // List has more than n elements.
  while (i->next) {
    i = i->next;
    ii = ii->next;
  }
  
  // Now ii is one step before the element to remove.
  ListNode *toRemove = ii->next;
  ii->next = toRemove->next;
  delete toRemove;
  
  return head;
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

  ListNode *newHead = removeNthFromEnd(head, 2);
  
  i = newHead;
  while (i) { std::cout << i->val << ' ', i = i->next; }
  std::cout << '\n';
}
