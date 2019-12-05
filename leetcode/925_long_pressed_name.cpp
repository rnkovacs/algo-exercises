/* Your friend is typing his name on a keyboard. Sometimes a key might be
 * long pressed, and the character will be typed 2 or more times.
 * Examine the typed characters. Return true if it is possible that it was
 * your friend's name with some characters long pressed.
 *
 * Runtime: 4 ms, faster than 64.78% of C++ online submissions.
 * Memory usage: 8.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

bool isLongPressedName(std::string name, std::string typed) {
  int i = 0;
  int nlen = name.size();
  int j = 0;
  int tlen = typed.size();
  while (i < nlen && j < tlen) {
    if (typed[j] == name[i]) {
      i++;
      j++;
      continue;
    }
    if (typed[j] == name[i-1]) {
      j++;
      continue;
    }
    return false;
  }
  return i == nlen;
}

int main() {
  std::string name = "alex";
  std::string typed = "aaleex";
  std::cout << name << '\n' << typed << '\n'
            << isLongPressedName(name, typed) << "\n\n";

  name = "saeed";
  typed = "ssaaedd";
  std::cout << name << '\n' << typed << '\n'
            << isLongPressedName(name, typed) << "\n\n";

  name = "laiden";
  typed = "laiden";
  std::cout << name << '\n' << typed << '\n'
            << isLongPressedName(name, typed) << '\n';
}
