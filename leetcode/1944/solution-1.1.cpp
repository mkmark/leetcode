/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime
159 ms
Beats
99.69%
Memory
83 MB
Beats
99.69%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = size(heights);
    /// s stores the index of heights such that f(x) = heights[s[x]] is mono
    /// decrease
    int s[n];
    vi res(n);
    res[n - 1] = 0;
    s[0] = n - 1;
    int s_size = 1;
    for (int i = n - 2; i >= 0; --i) {
      int popcount = 0;
      bool s_empty = 0;
      while (!s_empty && heights[s[s_size - 1]] < heights[i]) {
        --s_size;
        ++res[i];
        s_empty = s_size == 0;
      }
      s[s_size++] = i;
      res[i] += 1 - s_empty;
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
