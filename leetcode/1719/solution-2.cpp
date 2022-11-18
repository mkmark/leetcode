/*
author: mark@mkmark.net
time: O()
space: O()

reference: leetcode 517ms solution
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
 public:
  int checkWays(vector<vector<int>>& pairs) {
    unordered_map<int, int> numsIdx;
    int idx = 0;
    for (auto& p : pairs) {
      if (numsIdx.count(p[0]) == 0) {
        numsIdx[p[0]] = idx++;
      }
      if (numsIdx.count(p[1]) == 0) {
        numsIdx[p[1]] = idx++;
      }
    }
    const int n = numsIdx.size();

    vector<bitset<501>> allsubsets(n, bitset<501>());
    auto subsets = [&numsIdx, &allsubsets ](int num) -> auto& {
      return allsubsets[numsIdx[num]];
    };

    for (auto& p : pairs) {
      int f = p[0], t = p[1];
      subsets(f)[t] = 1;
      subsets(f)[f] = 1;
      subsets(t)[f] = 1;
      subsets(t)[t] = 1;
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
      int a = p[0], b = p[1];
      bool acbpob = (subsets(a) | subsets(b)) == subsets(a);
      bool bcbpoa = (subsets(b) | subsets(a)) == subsets(b);

      if (!acbpob && !bcbpoa) {
        return 0;
      }

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
