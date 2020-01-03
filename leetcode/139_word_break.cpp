/* Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 *
 * Runtime: 12 ms, faster than 61.25% of C++ online submissions.
 * Memory usage: 14.4 MB, less than 43.40% of C++ online submissions.
 */

#include <iostream>
#include <unordered_set>
#include <vector>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
  std::unordered_set<std::string> dict;
  for (std::string word : wordDict) dict.insert(word);
  
  int N = s.size();
  std::vector<bool> dp(N+1, false);
  dp[0] = true;
  
  for (int i=1; i<=N; i++) {
    for (int j=0; j<i; j++) {
      if (dp[j] && dict.count(s.substr(j, i-j))) {
        dp[i] = true;
        break;
      }
    }
  }
  
  return dp[N];
}

int main() {
  std::vector<std::string> d1 {"apple", "pen"};
  std::cout << "applepenapple | ";
  for (std::string s: d1) std::cout << s << ' ';
  std::cout << "\n" << wordBreak("applepenapple", d1) << "\n\n";
  
  std::cout << "catsandog | ";
  std::vector<std::string> d2 {"cats", "dog", "sand", "and", "cat"};
  for (std::string s: d2) std::cout << s << ' ';
  std::cout << "\n" << wordBreak("catsandog", d2) << '\n';
}
