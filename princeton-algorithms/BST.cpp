#include <cstdlib>
#include <iostream>

template <typename T>
struct Node {
  T val;
  Node<T> *left;
  Node<T> *right;
  int count;
  Node(T val) : val(val), left(nullptr), right(nullptr), count(1) {}
};

template <typename T>
class OrderedSet {
  Node<T> *root;

public:
  OrderedSet() : root(nullptr) {}
  ~OrderedSet() { while (root) removeMin(); }

  int size(Node<T> *node) const {
    if (!node) return 0;
    return node->count;
  }

  int size() const { return size(root); }

  Node<T> *insert(Node<T> *node, T x) {
    if (!node) return new Node<T>(x);

    if (x < node->val)
      node->left = insert(node->left, x);
    else if (x > node->val)
      node->right = insert(node->right, x);
    else 
      node->val = x;
    
    node->count = 1 + size(node->left) + size(node->right);
    return node;
  }

  void insert(T x) {
    root = insert(root, x);
  }

  bool contains(T x) const {
    Node<T> *i = root;
    while (i) {
      if (x < i->val) i = i->left;
      else if (x > i->val) i = i->right;
      else return true;
    }
    return false;
  }

  Node<T> *min(Node<T> *node) const {
    if (!node) return nullptr;
    while (node->left) node = node->left;
    return node;
  }

  T min() const {
    if (!root) return -999; // FIXME: less lame error value
    return min(root)->val;
  }

  Node<T> *removeMin(Node<T> *node) {
    if (!node) return nullptr; 
    if (!node->left) {
      Node<T> *remainder = node->right;
      delete node;
      return remainder;
    }
    node->left = removeMin(node->left);
    node->count = 1 + size(node->left) + size(node->right);
  }

  void removeMin() {
    root = removeMin(root);
  }

  // Hibbard deletion.
  Node<T> *remove(Node<T> *node, int x) {
    if (!node) return nullptr;

    if (x < node->val)
      node->left = remove(node->left, x);
    else if (x > node->val)
      node->right = remove(node->right, x);
    else {
      if (!node->right || !node->left) {
        Node<T> *remainder = (node->right) ? node->right : node->left;
        delete node;
        return remainder;
      }
      Node<T> *rightMin = min(node->right);
      node->right = removeMin(node->right);
      node->val = rightMin->val;
    }

    node->count = 1 + size(node->left) + size(node->right);
    return node;
  }

  void remove(T x) {
    root = remove(root, x);
  }

  int rank(Node<T> *node, int k) const {
    if (!node) return 0;
    if (k < node->val)
      return rank(node->left, k);
    else if (k > node->val)
      return size(node->left) + 1 + rank(node->right, k);
    else
      return size(node->left);
  }

  int rank(int k) const {
    return rank(root, k);
  }

  int floor(int k) const {
    if (!root) return -999; // FIXME
    Node<T> *i = root;
    while (i) {
      if (k < i->val) {
        if (!i->left) return -999; // FIXME
        i = i->left;
      }
      else if (k > i->val) {
        if (!i->right) return i->val;
        i = i->right;
      }
      else return i->val;
    }
  }

  int ceil(int k) const {
    if (!root) return -999; // FIXME
    Node<T> *i = root;
    while (i) {
      if (k < i->val) {
        if (!i->left || i->left->val < k)
          return i->val;
        i = i->left;
      }
      else if (k > i->val) {
        if (!i->right) return -999; // FIXME
        i = i->right;
      }
      else return i->val;
    }
  }

  void print(Node<T> *node) const {
    if (!node) return;
    print(node->left);
    std::cout << node->val << ' ';
    print(node->right);
  }

  void print() const {
    print(root);
    std::cout << '\n';
  }
};

int main() {
  OrderedSet<int> b;
  b.insert(5);
  b.print();
  b.insert(3);
  b.print();
  b.insert(4);
  b.print();
  b.insert(2);
  b.print();
  b.insert(6);
  b.print();
  std::cout << "contains 3: " << b.contains(3) << '\n';
  std::cout << "contains 7: " << b.contains(7) << '\n';
  std::cout << "min: " << b.min() << '\n';
  b.remove(2);
  b.print();
  std::cout << "size: " << b.size() << '\n';
  std::cout << "rank of 6: " << b.rank(6) << '\n';
  b.print();
  b.insert(2);
  b.remove(4);
  b.print();
  std::cout << "floor of 1: " << b.floor(1) << '\n';
  std::cout << "floor of 4: " << b.floor(4) << '\n';
  std::cout << "floor of 7: " << b.floor(7) << '\n';
  std::cout << "ceil of 1: " << b.ceil(1) << '\n';
  std::cout << "ceil of 4: " << b.ceil(4) << '\n';
  std::cout << "ceil of 7: " << b.ceil(7) << '\n';
}
