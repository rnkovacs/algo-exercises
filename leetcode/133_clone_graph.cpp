/* Given a reference of a node in a connected undirected graph, return a deep
 * copy of the graph.
 *
 * Runtime: 20 ms, faster than 94.80% of C++ online submissions.
 * Memory usage: 16.7 MB, less than 83.33% of C++ online submissions.
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

struct Node {
  int val;
  std::vector<Node *> neighbors;
  Node(int v, std::vector<Node *> n): val(v), neighbors(n) {}
};

void print(Node *node, std::set<Node *> &marked) {
  std::cout << node->val << ' ';
  marked.insert(node);

  for (Node *n : node->neighbors) {
    if (!marked.count(n)) print(n, marked);
  }
}

void print(Node *start) {
  std::set<Node *> marked;
  print(start, marked);
  std::cout << '\n';
}

Node *cloneGraph(Node *node, std::map<int, Node *> &nodes,
                             std::set<int> &marked) {
  int val = node->val;
  
  // Construct new node if needed.
  Node *newNode = (nodes.count(val))
                  ? nodes[val]
                  : new Node(val, {});
  nodes[val] = newNode;
  
  // Mark node.
  marked.insert(val);

  for (Node *neighbor : node->neighbors) {
    int nVal = neighbor->val;
    
    // Construct neighboring node if needed.
    Node *newNeighbor = (nodes.count(nVal))
                        ? nodes[nVal]
                        : new Node(nVal, {});
    nodes[nVal] = newNeighbor;
    
    // Add it to neighbors.
    newNode->neighbors.push_back(newNeighbor);
    
    // Clone unmarked neighbors recursively.
    if (!marked.count(nVal))
      cloneGraph(neighbor, nodes, marked);
  }
  
  // Return starter node.
  return newNode;
}
    
Node* cloneGraph(Node* node) {
  std::map<int, Node *> nodes;
  std::set<int> marked;
  return cloneGraph(node, nodes, marked);
}

int main() {
  Node *n1 = new Node(1, {});
  Node *n2 = new Node(2, {});
  Node *n3 = new Node(3, {});
  Node *n4 = new Node(4, {});
  n1->neighbors.push_back(n2);
  n1->neighbors.push_back(n3);
  n2->neighbors.push_back(n1);
  n2->neighbors.push_back(n4);
  n3->neighbors.push_back(n1);
  n3->neighbors.push_back(n4);
  n4->neighbors.push_back(n2);
  n4->neighbors.push_back(n3);

  print(n1);
  
  Node *n = cloneGraph(n1);

  print(n);
}
