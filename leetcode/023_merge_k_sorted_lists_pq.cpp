/* Merge k sorted lists and return it as one sorted list.
 *
 * Runtime: 28 ms, faster than 69.11% of C++ online submissions.
 * Memory usage: 11.3 MB, less than 50.00% of C++ online submissions.
 */

#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
  auto listComp = [](ListNode *n1, ListNode *n2)
                    { return n1->val > n2->val; };
  
  std::priority_queue<ListNode*,
                      std::vector<ListNode*>,
                      decltype(listComp)> q(listComp);
  
  for (ListNode *root : lists) {
    ListNode *i = root;
    while (i) {
        q.push(i);
        i = i->next;
    }
  }
  
  if (q.empty())
    return nullptr;

  ListNode *root = q.top();
  q.pop();
  
  ListNode *prev = root;
  while (!q.empty()) {
    ListNode *n = q.top();
    q.pop();
    prev->next = n;
    prev = n;
  }
  prev->next = nullptr;
  
  return root;
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
