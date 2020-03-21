#include <iostream>
#include <unordered_map>

std::unordered_map<char, int> arabic {    
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000} };

int romanToInt(std::string s) {
  int N = s.size();
  int value = 0;
  
  for (int i = 0; i < N; ++i) {
    if (i + 1 < N && arabic[s[i]] < arabic[s[i + 1]]) {
      value -= arabic[s[i]];
    } else {
      value += arabic[s[i]];
    }
  }
  
  return value;
}

int main() {
  std::cout << "III to arabic: " << romanToInt("III") << '\n';
  std::cout << "LVIII to arabic: " << romanToInt("LVIII") << '\n';
  std::cout << "MCMXCIV to arabic: " << romanToInt("MCMXCIV") << '\n';
}
