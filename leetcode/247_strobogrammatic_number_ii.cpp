/* A strobogrammatic number is a number that looks the same when rotated
 * 180 degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * Runtime: 76 ms, faster than 12.67% of C++ online submissions.
 * Memory usage: 21.3 MB, less than 100.00% of C++ online submissions.
 */

#include <vector>

void genStrobogrammatic(int n, std::string s, const std::vector<std::string> &pairs, 
                        std::vector<std::string> &res) {
    if (s.size() == n) {
        res.push_back(s);
        return;
    }
    
    for (auto &p : pairs) {
        if (s.size() == n - 2 && p[0] == '0')
            continue;

        std::string tmp = p[0] + s + p[1];
        if (s.empty() && n % 2) {
            if (p[0] != p[1]) continue;
            tmp = s + p[0];
        }

        genStrobogrammatic(n, tmp, pairs, res);
    }
}

std::vector<std::string> findStrobogrammatic(int n) {
    std::vector<std::string> pairs = { "69", "96", "88", "11", "00" };
    std::vector<std::string> res;
    genStrobogrammatic(n, "", pairs, res);
    return res;
}
