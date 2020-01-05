/* Given a singly linked list L_0 -> L_1 -> ... -> L_n-1 -> L_n,
 * reorder it to L_0 -> L_n -> L_1 -> L_n-1 -> L_2 -> L_n-2 -> ...
 * You may not modify the values in the list's nodes, only nodes themselves
 * can be changed.
 *
 * Runtime: 40 ms, faster than 99.72% of C++ online submissions.
 * Memory usage: 13 MB, less than 23.53% of C++ online submissions.
 */

#include <iostream>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
  if (!head) return;

  ListNode *i = head;
  std::stack<ListNode *> st;
  while (i) {
    st.push(i);
    i = i->next;
  }
  
  int N = st.size();
  int M = (N - 1) / 2;
  int count = 0;
  i = head;
  while (count < M) {
    ListNode *back = st.top();
    st.pop();
    
    ListNode *nextUp = i->next;
    i->next = back;
    back->next = nextUp;
    
    i = nextUp;
    count++;
  }
  if (!(N % 2)) i = i->next;
  i->next = nullptr;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  ListNode *i = head;
  while (i) { std::cout << i->val << ' '; i = i->next; }
  std::cout << '\n';

  reorderList(head);
  
  i = head;
  while (i) { std::cout << i->val << ' '; i = i->next; }
  std::cout << "\n\n";

  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = new ListNode(3);
  head2->next->next->next = new ListNode(4);
  head2->next->next->next->next = new ListNode(5);

  i = head2;
  while (i) { std::cout << i->val << ' '; i = i->next; }
  std::cout << "\n";

  reorderList(head2);

  i = head2;
  while (i) { std::cout << i->val << ' '; i = i->next; }
  std::cout << "\n";
}
