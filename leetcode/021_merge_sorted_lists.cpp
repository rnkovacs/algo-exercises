/*
 * Runtime: 12 ms, faster than 12.53% of C++ submissions.
 * Memory usage: 8.9 MB, less than 74.59% of C++ online submissions.
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

ListNode *merge(ListNode *l1, ListNode *l2) {
  ListNode *l3 = nullptr;
  ListNode *i1 = l1;
  ListNode *i2 = l2;
  ListNode *i3 = l3;

  if (l1 && l2) {
    if (l1->val < l2->val) {
      l3 = new ListNode(l1->val);
      i1 = l1->next;
      i2 = l2;
    } else {
      l3 = new ListNode(l2->val);
      i1 = l1;
      i2 = l2->next;
    }
    i3 = l3;
  }

  while (i1 && i2) {
    if (i1->val < i2->val) {
      i3->next = new ListNode(i1->val);
      i3 = i3->next;
      i1 = i1->next;
    } else {
      i3->next = new ListNode(i2->val);
      i3 = i3->next;
      i2 = i2->next;
    }
  }
  
  ListNode *i = (i1) ? i1 : i2;
  while (i) {
    if (!l3) {
      l3 = new ListNode(i->val);
      i3 = l3;
    } else {
      i3->next = new ListNode(i->val);
      i3 = i3->next;
    }
    i = i->next;
  }

  return l3;
}

int main() {
  ListNode *l1 = new ListNode(-10);
  l1->next = new ListNode(-6);
  l1->next->next = new ListNode(4);
  print("1", l1);
  ListNode *l2 = nullptr;
  print("2", l2);
  ListNode *l3 = merge(l1, l2);
  print("merged", l3);
  std::cout << '\n';

  l1 = nullptr;
  print("1", l1);
  l2 = new ListNode(0);
  print("2", l2);
  l3 = merge(l1, l2);
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
  l3 = merge(l1, l2);
  print("merged", l3);
}
