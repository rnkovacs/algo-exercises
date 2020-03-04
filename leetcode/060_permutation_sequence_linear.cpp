/* The set [1,2,3,...,n] contains a total of n! unique permutations.
 * Listing all the permutations in order, return the kth permutation sequence.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.5 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>
#include <vector>

std::string getPermutation(int n, int k) {
    std::vector<int> factorial(n, 1);
    for (int i = n-3, factor = 2; i >= 0; --i, ++factor) {
        factorial[i] = factorial[i+1] * factor;
    }
    
    std::string seq;
    for (int i = 0; i < n; ++i) seq += '1' + i;
    
    k--;
    
    int digitIdx;
    std::string result;
    
    for (int i = 0; i < n; ++i) {
        digitIdx = k / factorial[i];
        result += seq[digitIdx];
        seq = seq.substr(0, digitIdx) +
              seq.substr(digitIdx + 1, seq.size() - digitIdx - 1);
        k = k % factorial[i];
    }
    
    return result;
}

int main() {
  std::cout << getPermutation(3, 3) << '\n';
}
