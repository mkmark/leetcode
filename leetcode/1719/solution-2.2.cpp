/*
author: mark@mkmark.net
time: O()
space: O()

reference: leetcode 517ms solution

Runtime
335 ms
Beats
100%
Memory
110.7 MB
Beats
94.81%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const uint N = 501;

class Solution {
 public:
  int checkWays(vector<vector<int>>& pairs) {
    /// compress the index
    int compress[N];
    memset(compress, -1, sizeof compress);
    int n = 0;
    for (auto& pair : pairs) {
      if (compress[pair[0]] != -1) {
        pair[0] = compress[pair[0]];
      } else {
        compress[pair[0]] = n;
        pair[0] = n++;
      }
      if (compress[pair[1]] != -1) {
        pair[1] = compress[pair[1]];
      } else {
        compress[pair[1]] = n;
        pair[1] = n++;
      }
    }

    vector<bitset<500>> allsubsets(n, bitset<500>());

    for (auto& p : pairs) {
      int f = p[0], t = p[1];
      allsubsets[f][t] = 1;
      allsubsets[f][f] = 1;
      allsubsets[t][f] = 1;
      allsubsets[t][t] = 1;
    }

    bool hasRoot = false;
    for (auto& s : allsubsets) {
      if (s.count() == n) {
        hasRoot = true;
        break;
      }
    }
    if (!hasRoot) {
      return 0;
    }

    int ways = 0;
    for (auto& p : pairs) {
      /// if a and b are connected
      int a = p[0], b = p[1];
      /// either b ∈ a
      bool acbpob = (allsubsets[a] | allsubsets[b]) == allsubsets[a];
      /// or a ∈ b
      bool bcbpoa = (allsubsets[b] | allsubsets[a]) == allsubsets[b];

      /// if neither, 0
      if (!acbpob && !bcbpoa) {
        return 0;
      }

      /// if both, 2
      if (acbpob && bcbpoa) {
        ways = max(ways, 2);
      }

      ways = max(ways, 1);
    }
    return ways;
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
