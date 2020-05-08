/* Given a reference of a node in a connected undirected graph, return a deep
 * copy of the graph.
 *
 * Runtime: 12 ms, faster than 18.15% of C++ online submissions.
 * Memory usage: 9.1 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

struct Node {
  int val;
  std::vector<Node *> neighbors;
  Node(int v, std::vector<Node *> n): val(v), neighbors(n) {}
};

Node *cloneGraph(Node* node, std::unordered_map<int, Node*> &cloned) {
  if (!node) return nullptr;
  
  if (cloned.find(node->val) != cloned.end())
    return cloned[node->val];
  
  Node* clone = new Node(node->val, {});
  cloned[node->val] = clone;
  
  for (Node *n : node->neighbors) {
    clone->neighbors.push_back(cloneGraph(n, cloned));
  }
      
  return clone;
}

Node* cloneGraph(Node* node) {
  std::unordered_map<int, Node *> cloned;
  return cloneGraph(node, cloned);
}
