#include <iostream>
#include <vector>

struct Node {
  int val;
  std::vector<Node *> adj;
  Node(int v): val(v) {}
};

struct Graph {
  std::vector<Node *> nodes;
  int N;
  Graph(std::vector<Node *> v) : nodes(v), N(v.size()) {}
};

void CC(Node *n, int cid, std::vector<bool> &marked, std::vector<int> &id) {
  marked[n->val - 1] = true;
  id[n->val - 1] = cid;
  for (Node *i : n->adj) {
    if (!marked[i->val - 1]) CC(i, cid, marked, id);
  }
}

int numConnectedComponents(Graph g) {
  int count = 0;
  std::vector<bool> marked (g.N, false);
  std::vector<int> id (g.N, -1);
  
  for (Node *n : g.nodes) {
    if (!marked[n->val - 1])
      CC(n, count++, marked, id);
  }

  return count;
}

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  n1->adj.push_back(n2);
  n1->adj.push_back(n3);
  n2->adj.push_back(n1);
  n3->adj.push_back(n1);

  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  n4->adj.push_back(n5);
  n5->adj.push_back(n4);

  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  n6->adj.push_back(n7);
  n7->adj.push_back(n6);

  Graph g({n1, n2, n3, n4, n5, n6, n7});

  std::cout << numConnectedComponents(g) << '\n';
}
