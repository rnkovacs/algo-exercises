/* Given a linked list, determine if it has a cycle in it.
 *
 * Runtime: 12 ms, faster than 74.34% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  if (!head || !head->next || !head->next->next)
    return false;
  
  ListNode *slow = head;
  ListNode *fast = head->next->next;
  
  while (fast && slow != fast) {
    slow = slow->next;
    if (!fast->next) return false;
    fast = fast->next->next;
  }
  
  return fast;
}

int main() {
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;

  std::cout << hasCycle(head) << '\n';
}
