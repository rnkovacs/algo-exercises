/* You are playing the following Bulls and Cows game with your friend: You
 * write down a number and ask your friend to guess what the number is. Each
 * time your friend makes a guess, you provide a hint that indicates how many
 * digits in said guess match your secret number exactly in both digit and
 * position (called "bulls") and how many digits match the secret number but
 * locate in the wrong position (called "cows"). Your friend will use 
 * successive guesses and hints to eventually derive the secret number.
 *
 * Write a function to return a hint according to the secret number and
 * friend's guess, use A to indicate the bulls and B to indicate the cows. 
 *
 * Please note that both secret number and friend's guess may contain
 * duplicate digits.
 *
 * Runtime: 20 ms, faster than 7.30% of C++ online submissions.
 * Memory usage: 9 MB, less than 61.54% of C++ online submissions.
 */

#include <unordered_set>

std::string getHint(std::string secret, std::string guess) {
  int bulls = 0;
  int cows = 0;
  
  std::unordered_multiset<int> set;
  
  for (int i = 0; i < secret.size(); ++i) {
    if (secret[i] == guess[i]) ++bulls;
    else set.insert( secret[i] );
  }
  
  for (int i = 0; i < guess.size(); ++i) {
    if (secret[i] == guess[i]) continue;
    
    if (set.find(guess[i]) != set.end()) {
      ++cows;
      set.erase(set.find(guess[i]));
    }
  }
  
  return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
}
