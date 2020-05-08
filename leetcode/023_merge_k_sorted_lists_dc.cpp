/* Merge k sorted lists and return it as one sorted list.
 *
 * Runtime: 32 ms, faster than 72.90% of C++ online submissions.
 * Memory usage: 9.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(std::vector<ListNode*> &lists, int from, int to) {
  if (from == to) return lists[from];
  
  int mid = from + (to - from) / 2;
  ListNode *h1 = mergeKLists(lists, from, mid);
  ListNode *h2 = mergeKLists(lists, mid + 1, to);
  
  if (!h1 && !h2) return nullptr;
  if (!h1) return h2;
  if (!h2) return h1;

  ListNode *head;
  if (h1 && h2) {
    if (h1->val < h2->val) {
      head = h1;
      h1 = h1->next;
    } else {
      head = h2;
      h2 = h2->next;
    }
  }
        
  ListNode *i = head;
  
  while (h1 && h2) {
    if (h1->val < h2->val) {
      i->next = h1;
      h1 = h1->next;
    } else {
      i->next = h2;
      h2 = h2->next;
    }
    i = i->next;
  }
  
  ListNode *rest = (h1) ? h1 : h2;
  while (rest) {
    i->next = rest;
    rest = rest->next;
    i = i->next;
  }
  
  return head;
}
    
ListNode* mergeKLists(std::vector<ListNode*> &lists) {
  if (lists.empty()) return nullptr;
  return mergeKLists(lists, 0, lists.size() - 1);
} 

void deleteList(ListNode *i) {
  while (i) {
    ListNode *n = i;
    i = i->next;
    delete n;
  }
}

int main() {
  ListNode *root1 = new ListNode(1);
  root1->next = new ListNode(4);
  root1->next->next = new ListNode(5);

  ListNode *root2 = new ListNode(1);
  root2->next = new ListNode(3);
  root2->next->next = new ListNode(4);

  ListNode *root3 = new ListNode(2);
  root3->next = new ListNode(6);

  std::vector<ListNode *> v {root1, root2, root3};
  ListNode *root4 = mergeKLists(v);

  ListNode *i = root4;
  while (i) {
    std::cout << i->val << ' ';
    i = i->next;
  }
  std::cout << '\n';

  deleteList(root1);
  deleteList(root2);
  deleteList(root3);
  deleteList(root4);
}
