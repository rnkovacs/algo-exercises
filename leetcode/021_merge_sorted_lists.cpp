/*
 * Runtime: 8 ms, faster than 92.97% of C++ submissions.
 * Memory usage: 8.6 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void print(std::string name, ListNode *head) {
  std::cout << name << ": ";
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << std::endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;
  
  ListNode *head;
  if (l1->val < l2->val) {
    head = l1;
    l1 = l1->next;
  } else {
    head = l2;
    l2 = l2->next;
  }
  
  ListNode *i = head;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      i->next = l1;
      l1 = l1->next;
    } else {
      i->next = l2;
      l2 = l2->next;
    }
    i = i->next;
  }
  
  // One of the lists has ended.
  ListNode *rest = l1 ? l1 : l2;
  while (rest) {
    i->next = rest;
    rest = rest->next;
    i = i->next;
  }
  
  return head;
}

int main() {
  ListNode *l1 = new ListNode(-10);
  l1->next = new ListNode(-6);
  l1->next->next = new ListNode(4);
  print("1", l1);
  ListNode *l2 = nullptr;
  print("2", l2);
  ListNode *l3 = mergeTwoLists(l1, l2);
  print("merged", l3);
  std::cout << '\n';

  l1 = nullptr;
  print("1", l1);
  l2 = new ListNode(0);
  print("2", l2);
  l3 = mergeTwoLists(l1, l2);
  print("merged", l3);
  std::cout << '\n';

  l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  print("1", l1);
  l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);
  print("2", l2);
  l3 = mergeTwoLists(l1, l2);
  print("merged", l3);
}
