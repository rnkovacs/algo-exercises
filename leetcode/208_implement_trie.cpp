/* Implement a trie with insert, search and startsWith methods.
 *
 * Runtime: 128 ms, faster than 16.89% of C++ online submissions.
 * Memory usage: 222.5 MB, less than 6.67% of C++ online submissions.
 */

#include <iostream>
#include <vector>

struct TrieNode {
  std::vector<TrieNode *> child;
  bool isEnd;
  TrieNode() : child(26, nullptr), isEnd(false) {}
};

class Trie {
  TrieNode *root;

public:
  Trie() : root(nullptr) {}
    
  TrieNode *insert(TrieNode *node, std::string word, int d) {
    if (!node) node = new TrieNode();
    
    if (d == word.size()) {
      node->isEnd = true;
      return node;
    }
    
    int idx = word[d] - 'a';
    node->child[idx] = insert(node->child[idx], word, d+1);
    
    return node;
  }
    
  void insert(std::string word) {
    root = insert(root, word, 0);
  }
  
  TrieNode *search(TrieNode *node, std::string word, int d) {
    if (!node) return node;
    
    if (d == word.size())
      return node;
    
    int idx = word[d] - 'a';
    return search(node->child[idx], word, d+1);
  }
  
  bool search(std::string word) {
    TrieNode *node = search(root, word, 0);
    if (!node || !node->isEnd) return false;
    return true;
  }
    
  bool startsWith(std::string prefix) {
    TrieNode *node = search(root, prefix, 0);
    if (!node) return false;
    return true;
  }
};

int main() {
  Trie t;
  t.insert("apple");
  std::cout << "added apple\n";
  std::cout << "apple in trie: " << t.search("apple") << '\n';
  std::cout << "app in trie: " << t.search("app") << '\n';
  std::cout << "startswith app: " << t.startsWith("app") << '\n';
  t.insert("app");
  std::cout << "added app\n";
  std::cout << "app in trie: " << t.search("app") << '\n';
}
