/* Given an array of strings arr. String s is a concatenation of a
 * sub-sequence of arr which have unique characters.
 *
 * Return the maximum possible length of s.
 *
 * Runtime: 24 ms, faster than 58.87% of C++ online submissions.
 * Memory usage: 6.3 MB, less than 100.00% of C++ online submissions.
 */

int concatStrings(const std::vector<unsigned> &profiles, int i, unsigned s) {
  if (i == profiles.size()) {
    // Count number of set bits in s.
    int count = 0;
    while (s) {
      s &= (s - 1);
      ++count;
    }
    return count;
  }
  
  // One option: don't include this string in the set.
  int one = concatStrings(profiles, i + 1, s);
  
  // Other option: include it.
  // But only if it doesn't overlap with s.
  if ((profiles[i] & s) == 0)
    s |= profiles[i];
  
  int two = concatStrings(profiles, i + 1, s);
  
  return std::max(one, two);
}
    
int maxLength(std::vector<std::string> &arr) {
  if (arr.empty()) return 0;
  
  std::vector<unsigned> profiles;
  unsigned profile;
  unsigned charID;
  bool duplicate;
  
  for (const std::string &s: arr) {
    duplicate = false;
    profile = 0;
    for (char c: s) {
      charID = 1 << (c - 'a');
      if (charID & profile) {
        duplicate = true;
        break;
      }
      profile |= charID;
    }
    if (!duplicate)
      profiles.push_back(profile);
  }
  
  return concatStrings(profiles, 0, 0);
}
