/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime
290 ms
Beats
69.77%
Memory
84 MB
Beats
90.78%
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
    stack<int> s;
    vi res(n);
    res[n - 1] = 0;
    s.emplace(n - 1);
    for (int i = n - 2; i >= 0; --i) {
      int height = heights[i];
      int popcount = 0;
      bool s_empty = 0;
      while (!s_empty && heights[s.top()] < height) {
        s.pop();
        ++popcount;
        s_empty = s.empty();
      }
      s.emplace(i);
      res[i] = popcount + (s_empty ? 0 : 1);
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
