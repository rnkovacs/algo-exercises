/* Given a singly linked list, determine if it is a palindrome.
 *
 * Runtime: 20 ms, faster than 93.58% of C++ online submissions.
 * Memory usage: 12.5 MB, less than 82.76% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val): val(val), next(nullptr) {}
};

ListNode *reverseList(ListNode *head) {
  if (!head || !head->next) return head;
  
  ListNode *newHead = reverseList(head->next);
  
  // 1 -> 2 -> 3 -> null
  //      3 -> 2 -> 1 -> null
  head->next->next = head;
  head->next = nullptr;
  
  return newHead;
}
    
bool isPalindrome(ListNode* head) {
  if (!head || !head->next) return true;

  // First find out length.
  int len = 0;
  ListNode *i = head;
  while (i) {
    i = i->next;
    ++len;
  }
  
  // Go to list's half.
  int halfLen = len / 2;
  i = head;
  while (halfLen > 0) {
    i = i->next;
    halfLen--;
  }
  if (len % 2) i = i->next;
  
  ListNode *firstHalf = head;
  ListNode *secondHalf = reverseList(i);
  
  // Check first half and reversed second half for equality.
  while (secondHalf) {
    if (firstHalf->val != secondHalf->val)
      return false;

    firstHalf = firstHalf->next;
    secondHalf = secondHalf->next;
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
