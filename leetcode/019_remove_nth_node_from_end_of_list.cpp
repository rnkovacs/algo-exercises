/* Given a linked list, remove the nth node from the end of the list
 * and return its head..
 *
 * Runtime: 4 ms, faster than 94.32% of C++ online submissions.
 * Memory usage: 8.2 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if (!head) return nullptr;
  
  ListNode *tail = head;
  while (n > 1 && tail) {
    tail = tail->next;
    --n;
  }
  
  if (!tail->next) {
    // List has exactly n elements, we remove head.
    // 1 -> 2 | n = 2
    ListNode *oldHead = head;
    head = oldHead->next;
    delete oldHead;
    return head;
  }
  
  // List has more than n elements, we look for the one before the nth.
  // 1 -> 2 -> 3 | n = 2
  ListNode *beforeNth = head;
  tail = tail->next;
  
  while (tail->next) {
    tail = tail->next;
    beforeNth = beforeNth->next;
  }
  
  ListNode *toRemove = beforeNth->next;
  beforeNth->next = toRemove->next;
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
