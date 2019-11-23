/* 
 * Given an array of integers, find the length of the longest subarray
 * having the sum of its elements at most k, where k > 0.
 *
 * E.g. Input: [1, 2, 1, 0, 1, 1, 0], k = 4.
 *      Output: 5.
 *      Explanation: [1, 0, 1, 1, 0].
 */

#include <iostream>

int longest_subarray_with_sum_k(int *A, int A_len, int k) {
  int max_len = 0;
  
  int sum = 0;
  int len = 0;
  int i = 0;

  for (int start = 0; start < A_len; ++start) {
    i = start;

    while (i < A_len) {
      if (sum + A[i] > k) {
        if (len > max_len) max_len = len;
        sum = 0;
        len = 0;
        break;
      }
      
      sum += A[i];
      ++len;
      ++i;

      if (i == A_len) {
        if (len > max_len) max_len = len;
        sum = 0;
        len = 0; 
      }
    }

  }

  return max_len;
}

int main() {
  int a[] = {1, 2, 1, 0, 1, 1, 0};
  for (int elem : a) std::cout << elem << ' ';
  std::cout << '\n';

  int k = 4;
  std::cout << "Length of longest subarray with sum <= " << k << ":\n"
            << longest_subarray_with_sum_k(a, sizeof(a)/sizeof(a[0]), k)
            << '\n';

  k = 100;
  std::cout << "Length of longest subarray with sum <= " << k << ":\n"
            << longest_subarray_with_sum_k(a, sizeof(a)/sizeof(a[0]), k)
            << '\n';

  k = 1;
  std::cout << "Length of longest subarray with sum <= " << k << ":\n"
            << longest_subarray_with_sum_k(a, sizeof(a)/sizeof(a[0]), k)
            << '\n';

  k = 0;
  std::cout << "Length of longest subarray with sum <= " << k << ":\n"
            << longest_subarray_with_sum_k(a, sizeof(a)/sizeof(a[0]), k)
            << '\n';

  k = -1;
  std::cout << "Length of longest subarray with sum <= " << k << ":\n"
            << longest_subarray_with_sum_k(a, sizeof(a)/sizeof(a[0]), k)
            << '\n';

  return 0;
}
