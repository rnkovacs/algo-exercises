#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

struct Node {
  int val;
  std::vector<Node *> children;
  Node(int v) : val(v) {}
};

struct Graph {
  std::vector<Node *> nodes;
};

bool is_route_between(Graph g, Node *v1, Node *v2) {
  if (v1 == v2)
    return true;

  auto begin = g.nodes.begin();
  auto end = g.nodes.end();
  if (std::find(begin, end, v1) == end ||
      std::find(begin, end, v2) == end)
    return false;

  std::deque<Node *> q;
  for (Node *n : v1->children)
    q.push_back(n);

  while (!q.empty()) {
    Node *n = q.front();
    q.pop_front();
    
    if (n == v2)
      return true;
    
    for (Node *i : n->children)
      q.push_back(i);
  }

  return false;
}

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  n1->children = { n5 };
  n2->children = { n4 };
  n3->children = { n1, n2 };
  n5->children = { n2, n3 };
  Graph g1 { {n1, n2, n3, n4, n5} };
  
  std::cout << "1 2\n" << is_route_between(g1, n1, n2) << "\n\n";
  std::cout << "4 4\n" << is_route_between(g1, n4, n4) << "\n\n";
  std::cout << "1 6\n" << is_route_between(g1, n1, new Node(6)) << "\n\n";

  Graph g2;
  Node *n7;
  std::cout << "1 2\n" << is_route_between(g2, n1, n2) << "\n\n";
  std::cout << "1 7\n" << is_route_between(g2, n1, n7) << '\n';
}
