/* You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.
 *
 * Runtime: 32 ms, faster than 53.04% of C++ online submissions.
 * Memory usage: 13.5 MB, less than 22.22% of C++ online submissions.
 */

#include <cassert>
#include <iostream>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;
  
  ListNode *i = nullptr;
  
  std::stack<ListNode *> l1st;
  i = l1;
  while (i) { l1st.push(i); i = i->next; }
  
  std::stack<ListNode *> l2st;
  i = l2;
  while (i) { l2st.push(i); i = i->next; }
  
  std::stack<ListNode *> res;
  int carry = 0;
        
  while (!l1st.empty() && !l2st.empty()) {
    int val = l1st.top()->val + l2st.top()->val + carry;
    l1st.pop();
    l2st.pop();
    carry = val / 10;
    val = val % 10;
    res.push(new ListNode(val));
  }
  
  if (!l1st.empty() || !l2st.empty()) {
    std::stack<ListNode *> &rem = l1st.empty() ? l2st : l1st;
    while (!rem.empty()) {
      int val = rem.top()->val + carry;
      rem.pop();
      carry = val / 10;
      val = val % 10;
      res.push(new ListNode(val));
    }
  }
  assert(l1st.empty() && l2st.empty() && "Stacks not empty!");
  
  if (carry) res.push(new ListNode(carry));
  
  ListNode *head = res.top();
  res.pop();
  
  i = head;
  while (!res.empty()) {
    i->next = res.top();
    res.pop();
    i = i->next;
  }
    
  return head;
}
