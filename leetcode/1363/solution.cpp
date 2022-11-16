/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime
18 ms
Beats
95.53%
Memory
19.3 MB
Beats
92.28%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
 public:
  string largestMultipleOfThree(vector<int>& digits) {
    int n = size(digits);
    auto sum = accumulate(all(digits), 0);
    auto rem_sum = sum % 3;

    int rtrim = 0;
    if (rem_sum != 0) {
      // find the two least num
      int m1_1 = 10;
      int m1_2 = 10;
      int m2_1 = 10;
      int m2_2 = 10;
      int m1_1_index;
      int m1_2_index;
      int m2_1_index;
      int m2_2_index;

      for (int i = 0; i < n; ++i) {
        auto digit = digits[i];
        if (digit % 3 == 1) {
          if (digit < m1_1) {
            m1_2 = m1_1;
            m1_2_index = m1_1_index;
            m1_1 = digit;
            m1_1_index = i;
          } else if (digit == m1_1 && digit < m1_2) {
            m1_2 = digit;
            m1_2_index = i;
          }
        } else if (digit % 3 == 2) {
          if (digit < m2_1) {
            m2_2 = m2_1;
            m2_2_index = m2_1_index;
            m2_1 = digit;
            m2_1_index = i;
          } else if (digit == m2_1 && digit < m2_2) {
            m2_2 = digit;
            m2_2_index = i;
          }
        }
      }

      /// replace the 1 or 2 least num with 0
      if (rem_sum == 1) {
        if (m1_1 != 10) {
          digits[m1_1_index] = 0;
          rtrim = 1;
        } else if (m2_1 != 10 && m2_2 != 10) {
          digits[m2_1_index] = 0;
          digits[m2_2_index] = 0;
          rtrim = 2;
        } else {
          return "";
        }
      } else if (rem_sum == 2) {
        if (m2_1 != 10) {
          digits[m2_1_index] = 0;
          rtrim = 1;
        } else if (m1_1 != 10 && m1_2 != 10) {
          digits[m1_1_index] = 0;
          digits[m1_2_index] = 0;
          rtrim = 2;
        } else {
          return "";
        }
      }
    }

    if (n == rtrim) return "";

    sort(all(digits), greater());
    if (digits[0] == 0) return "0";

    /// trim the replaced 0, and cast
    string res;
    res.reserve(n - rtrim);
    for (int i = 0; i < n - rtrim; ++i) {
      res += digits[i] + 48;
    }
    return res;
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
