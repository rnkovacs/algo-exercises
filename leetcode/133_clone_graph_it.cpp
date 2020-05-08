/* Given a reference of a node in a connected undirected graph, return a deep
 * copy of the graph.
 *
 * Runtime: 8 ms, faster than 71.97% of C++ online submissions.
 * Memory usage: 8.9 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <unordered_map>
#include <queue>

struct Node {
  int val;
  std::vector<Node *> neighbors;
  Node(int v, std::vector<Node *> n): val(v), neighbors(n) {}
};

Node* cloneGraph(Node* node) {
  if (!node) return nullptr;
  
  std::queue<Node *> q;
  std::unordered_map<int, Node *> m;
  
  q.push(node);
  m[node->val] = new Node(node->val, {});
  
  while (!q.empty()) {
    Node *orig = q.front();
    q.pop();
    Node *clone = m[orig->val];
    
    for (Node *n: orig->neighbors) {
      if (m.find(n->val) == m.end()) {
        m[n->val] = new Node(n->val, {});
        q.push(n);
      }
      clone->neighbors.push_back(m[n->val]);
    }
  }
  return m[node->val];
}
