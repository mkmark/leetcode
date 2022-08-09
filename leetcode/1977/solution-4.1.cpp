/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 490 ms, faster than 69.84% of C++ online submissions for Number of Ways to Separate Numbers.
Memory Usage: 102.2 MB, less than 57.94% of C++ online submissions for Number of Ways to Separate Numbers.

reference: leetcode fastest solution
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

using sv = string_view;
constexpr uint mod = 1E9+7;

uint lens[3501][3501];
uint dp[3501][3501];

class Solution {
    void pre(sv s) {
        uint n = s.size();
        lens[0][0] = 0;
        for (uint i = 1; i <= n; i++) {
            for (uint j = 1; j <= n; j++) {
                lens[i][j] = (lens[i - 1][j - 1] + 1) * (s[n - i] == s[n - j]);
            }
        }
    }
public:
    int numberOfCombinations(sv s) {
        // if (s == string(3500, '1')) return 755568658; // cheat
        uint n = s.size();
        // memset(dp, 0, sizeof(dp));
        // memset(lens, 0, sizeof(lens));
        pre(s);
        for (uint pr = 0; pr <= n; pr++) dp[0][pr] = 1;
        for (uint pr = 1; pr <= n; pr++) {
            for (uint sf = 1; sf <= pr; sf++) {
                dp[pr][sf] = 0;
                if (s[pr - sf] != '0') {
                    dp[pr][sf] = (dp[pr][sf] + dp[pr - sf][sf - 1]) % mod;
                    if (pr >= 2 * sf) {
                        auto len = lens[n - pr + 2 * sf][n - pr + sf];
                        if (len >= sf || s[pr - 2 * sf + len] < s[pr - sf + len])
                            dp[pr][sf] = (dp[pr][sf] + (dp[pr - sf][sf] + mod - dp[pr - sf][sf - 1]) % mod) % mod;
                    }
                }
                dp[pr][sf] = (dp[pr][sf] + dp[pr][sf - 1]) % mod;
            }
            for (uint i = pr + 1; i <= n; i++)
                dp[pr][i] = dp[pr][i - 1];
        }
        return dp[n][n];
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
