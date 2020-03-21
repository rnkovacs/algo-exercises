/* Given a singly linked list, determine if it is a palindrome.
 *
 * Runtime: 20 ms, faster than 93.58% of C++ online submissions.
 * Memory usage: 12.7 MB, less than 62.07% of C++ online submissions.
 */

#include <iostream>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val): val(val), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
  if (!head || !head->next) return true;

  // First find out length.
  int len = 0;
  ListNode *i = head;
  while (i) {
    i = i->next;
    ++len;
  }
  
  std::stack<int> s;
  int halfLen = len / 2;
  i = head;

  // Put elements on stack until n/2.
  while (halfLen > 0) {
    s.push(i->val);
    i = i->next;
    --halfLen;
  }
  
  // For odd-long lists, step over middle element.
  if (len % 2) i = i->next;
  
  // Check remaining elements against stack elements.
  while (i) {
    if (i->val != s.top())
      return false;
    s.pop();
    i = i->next;
  }
  
  return true;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  std::cout << isPalindrome(head) << '\n';

  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);
  std::cout << isPalindrome(head) << '\n';
}
