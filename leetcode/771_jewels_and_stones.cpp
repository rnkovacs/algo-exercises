/* You're given strings J representing the types of stones that are jewels,
 * and S representing the stones you have.  Each character in S is a type of
 * stone you have.  You want to know how many of the stones you have are also
 * jewels.
 *
 * The letters in J are guaranteed distinct, and all characters in J and S
 * are letters. Letters are case sensitive, so "a" is considered a different
 * type of stone from "A".
 *
 * Runtime: 4 ms, faster than 60.91% of C++ online submissions.
 * Memory usage: 6.3 MB, less than 100.00% of C++ online submissions.
 */

#include <unordered_set>

int numJewelsInStones(std::string J, std::string S) {
  std::unordered_set<char> jewels;
  for (char c : J) jewels.insert(c);
  
  int count = 0;
  for (char c : S) {
    if (jewels.find(c) != jewels.end()) ++count;
  }
  
  return count;
}
