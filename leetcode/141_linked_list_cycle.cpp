/* Given a linked list, determine if it has a cycle in it.
 *
 * Runtime: 12 ms, faster than 74.38% of C++ online submissions.
 * Memory usage: 9.7 MB, less than 96.05% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;
  
  while (fast && slow) {
    slow = slow->next;
    
    if (fast->next) fast = fast->next->next;
    else return false;
    
    if (fast && slow && fast == slow)
      return true;
  }
  
  return false;
}

int main() {
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;

  std::cout << hasCycle(head) << '\n';
}
