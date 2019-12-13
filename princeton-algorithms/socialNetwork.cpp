#include <fstream>
#include <iostream>
#include <vector>

class UnionFind {
  std::vector<int> parent;
  std::vector<int> size;
  int maxsize;

public:
  UnionFind(int n) : maxsize(1) {
    for (int i=0; i<n; ++i) {
      parent.push_back(i);
      size.push_back(1);
    }
  }

  int root(int n) {
    int r = parent[n];
    while (r != parent[r])
      r = parent[r];

    // Path compression.
    int i = parent[n];
    while (i != parent[i]) {
      i = parent[i];
      parent[i] = r;
    }

    return r;
  }

  void unite(int p, int q) {
    int pr = root(p);
    int qr = root(q);
    if (size[pr] < size[qr]) {
      parent[pr] = qr;
      size[qr] += size[pr];
      maxsize = (size[qr] > maxsize) ? size[qr] : maxsize;
    } else {
      parent[qr] = pr;
      size[pr] += size[qr];
      maxsize = (size[pr] > maxsize) ? size[pr] : maxsize;
    }
  }

  bool find(int p, int q) {
    return root(p) == root(q);
  }

  bool isFullyConnected() {
    return maxsize == parent.size();
  }

  void print() {
    for (int entry : parent)
      std::cout << entry << ' ';
    std::cout << '\n';
    for (int entry : size)
      std::cout << entry << ' ';
    std::cout << "\n\n";
  }
};

int main() {
  std::ifstream is("network.txt");
  if (!is.is_open()) {
    std::cerr << "File open failed\n";
    return -1;
  }

  int n;
  is >> n;
  
  UnionFind uf(n);
  int timestamp;
  int p;
  int q;
  while (is >> timestamp >> p >> q) {
    //uf.print();
    if (!uf.find(p, q))
      uf.unite(p, q);
    if (uf.isFullyConnected()) {
      std::cout << "Fully connected at " << timestamp << '\n';
      return 0;
    }
  }

  //uf.print();
  std::cout << "Never got fully connected\n";
  return 0; 
}
