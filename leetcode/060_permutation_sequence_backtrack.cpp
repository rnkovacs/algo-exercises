/* The set [1,2,3,...,n] contains a total of n! unique permutations.
 * Listing all the permutations in order, return the kth permutation sequence.
 *
 * This backtracking solution times out.
 */

#include <iostream>

bool getPermutation(int k, int &c, std::string prefix, std::string rem,
                    std::string &kth) {
    if (rem.size() == 0) {
        if (++c == k) {
            kth = prefix;
            return true;
        }
        return false;
    }
    
    for (int i = 0, N = rem.size(); i < N; ++i) {
        std::string newRem = rem.substr(0, i) + rem.substr(i + 1, N - i - 1);
        if (getPermutation(k, c, prefix + rem[i], newRem, kth))
            return true;
    }
    
    return false;
}

std::string getPermutation(int n, int k) {
    std::string all;
    for (int i=1; i<=n; ++i) all += '0' + i;
    
    std::string kth;
    int counter = 0;
    
    getPermutation(k, counter, "", all, kth);
    
    return kth;
}

int main() {
  std::cout << getPermutation(3, 3) << '\n';
}
