/* Given a singly linked list, return a random node's value from the linked
 * list. Each node must have the same probability of being chosen.
 *
 * Runtime: 40 ms, faster than 62.82% of C++ online submissions.
 * Memory usage: 16.5 MB, less than 25.00% of C++ online submissions.
 */

#include <iostream>
#include <random>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class List {
  ListNode *head;
  std::random_device rd;
  std::mt19937 gen;

public:
  List(const std::vector<int> &v) : head(nullptr), gen(rd()) {
    if (v.size() > 0) {
      head = new ListNode(v[0]);
      ListNode *prev = head;
      for (int i=1, size=v.size(); i<size; ++i) {
        ListNode *node = new ListNode(v[i]);
        prev->next = node;
        prev = node;
      }
    }
  }

  ~List() { deleteNode(head); }

  void deleteNode(ListNode *node) {
    if (!node) return;
    deleteNode(node->next);
    delete node;
  }

  int getRandom() {
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    
    ListNode *i = head;
    int randVal = i->val;
    int size = 0;
    
    while (i) {
      size++;
      if (dis(gen) < (double)1 / size)
        randVal = i->val;
      i = i->next;
    }

    return randVal;
  }
};

int main() {
  std::vector<int> v {1,2,3,4,5};
  List l(v);
  std::cout << l.getRandom() << '\n';
  std::cout << l.getRandom() << '\n';
  std::cout << l.getRandom() << '\n';
  std::cout << l.getRandom() << '\n';
  std::cout << l.getRandom() << '\n';
}
