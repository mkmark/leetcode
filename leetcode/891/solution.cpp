/*
author: mark@mkmark.net
time: O(nlogn)
space: O(1)

Runtime
116 ms
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
const int64_t TENMOD = 10000000070;

class Solution {
 public:
  int sumSubseqWidths(vector<int>& nums) {
    int n = size(nums);
    if (n == 1) {
      return 0;
    }

    /// O(nlogn)
    sort(all(nums));
    /// a_{n-1}
    int an_1 = nums[1];
    /// S_{n-2}
    int64_t sn_2 = 0;
    /// S_{n-1}
    int64_t sn_1 = nums[1] - nums[0];
    /// S_n
    int64_t sn = sn_1;
    /// 2^(n-1)
    int64_t p2n_1 = 4;
    for (int i = 2; i < n; ++i) {
      auto an = nums[i];
      sn = sn_1 * 3 - sn_2 * 2 + (p2n_1 - 1) * (an - an_1) + TENMOD;
      sn %= MOD;

      sn_2 = sn_1;
      sn_1 = sn;
      p2n_1 <<= 1;
      p2n_1 %= MOD;
      an_1 = an;
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
