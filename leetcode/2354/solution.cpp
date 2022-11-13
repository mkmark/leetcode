/*
author: mark@mkmark.net
time: O(nlogn)
space: O(n)

Runtime
485 ms
Beats
76.18%
Memory
101 MB
Beats
26.18%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
 public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    /// remove dup O(nlogn)
    set<int> s;
    int n = size(nums);
    for (int i = 0; i < n; ++i) {
      s.emplace(nums[i]);
    }
    nums.assign(s.begin(), s.end());
    n = size(nums);

    /// pop count and sort O(nlogn)
    vi popcount(n);
    for (int i = 0; i < n; ++i) {
      popcount[i] = __builtin_popcount(nums[i]);
    }
    sort(all(popcount));

    /// find match O(nlogn)
    auto popcount_begin = popcount.begin();
    auto popcount_end = popcount.end();
    long long ans = 0;
    for (int i =
             lower_bound(popcount_begin, popcount_end, k - popcount[n - 1]) -
             popcount_begin;
         i < n; ++i) {
      int t = popcount_end -
              lower_bound(popcount_begin + i, popcount_end, k - popcount[i]);
      ans += 2 * t;
      if (i == n - t) {
        --ans;
      }
    }
    return ans;
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
