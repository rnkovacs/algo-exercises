/* Given a column title as appear in an Excel sheet, return its
 * corresponding column number. For example:
 *
 *   A -> 1
 *   B -> 2
 *   ...
 *   Z -> 26
 *   AA -> 27
 *   AB -> 28 
 *   ...
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 5.9 MB, less than 100.00% of C++ online submissions.
 */

int titleToNumber(std::string s) {
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
        int digit = s[i] - 'A' + 1;
        num = 26 * num + digit;
    }
    return num;
}
