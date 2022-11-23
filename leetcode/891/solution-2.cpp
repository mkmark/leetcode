/*
author: mark@mkmark.net
time: O(nlogn)
space: O(1)

Runtime
103 ms
Beats
99.53%
Memory
53.8 MB
Beats
97.16%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int MOD = 1000000007;

class Solution {
 public:
  int sumSubseqWidths(vector<int>& nums) {
    int n = size(nums);
    if (n == 1) {
      return 0;
    }

    uint64_t sn = 0;
    uint64_t p2n_1 = 2;

    /// O(nlogn)
    sort(all(nums));
    for (int i = 1, j = n - 2; i < n; ++i, --j) {
      sn += (p2n_1 - 1) * (nums[i] - nums[j] + MOD);
      sn %= MOD;

      p2n_1 <<= 1;
      p2n_1 %= MOD;
    }
    return sn;
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
