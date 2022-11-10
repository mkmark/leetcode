/*
author: mark@mkmark.net
time: O(n)
space: O(1)

Runtime
42 ms
Beats
99.80%
Memory
22.1 MB
Beats
95.56%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
 public:
  bool canBeValid(string& s, string& locked) {
    int n = size(s);
    if (n % 2 == 1) return false;

    int state = 0;
    int flex = 0;
    int diff = 0;

    for (int i = 0; i < n; ++i) {
      if (locked[i] == '1') {
        if (s[i] == '(') {
          ++state;
        } else {
          --state;
          if (state == -1) {
            if (flex == 0) {
              return false;
            } else {
              ++state;
              --flex;
            }
          }
        }
      } else {
        ++flex;
      }
    }

    if (state > flex) return false;

    state = 0;
    flex = 0;

    for (int i = n - 1; i >= 0; --i) {
      if (locked[i] == '1') {
        if (s[i] == ')') {
          ++state;
        } else {
          --state;
          if (state == -1) {
            if (flex == 0) {
              return false;
            } else {
              ++state;
              --flex;
            }
          }
        }
      } else {
        ++flex;
      }
    }

    return true;
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
