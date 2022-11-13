/*
author: mark@mkmark.net
time: O(nlogn)
space: O(n)

Runtime
161 ms
Beats
100%
Memory
63.4 MB
Beats
93.98%

use vector instead of set to remove duplicates
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
    sort(all(nums));
    int n = size(nums);
    vi unique_nums(n);
    unique_nums[0] = nums[0];
    int unique_nums_count = 1;

    for (int i = 1; i < n; ++i) {
      if (nums[i] != nums[i - 1]) {
        unique_nums[unique_nums_count++] = nums[i];
      }
    }
    n = unique_nums_count;

    /// pop count and sort O(nlogn)
    vi popcount(n);
    for (int i = 0; i < n; ++i) {
      popcount[i] = __builtin_popcount(unique_nums[i]);
    }
    sort(all(popcount));

    /// find match O(nlogn)
    auto popcount_begin = popcount.begin();
    auto popcount_end = popcount.end();
    long long ans = 0;
    int j = lower_bound(popcount_begin, popcount_end, k - popcount[0]) -
            popcount_begin;

    for (int i =
             lower_bound(popcount_begin, popcount_end, k - popcount[n - 1]) -
             popcount_begin;
         i < n; ++i) {
      int target = k - popcount[i];
      while (j >= i && (j == n || popcount[j] >= target)) {
        --j;
      }
      ++j;
      ans += 2 * (n - j);
      if (i == j) {
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
