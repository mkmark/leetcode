/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 383 ms, faster than 72.22% of C++ online submissions for Number of Ways to Separate Numbers.
Memory Usage: 6.4 MB, less than 97.62% of C++ online submissions for Number of Ways to Separate Numbers.

reference: leetcode smallest solution
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int dp[3501];
int dpp[3501];

class Solution {
public:
    int numberOfCombinations(string_view num) {
        const int n = num.size(), mod = 1000000007;
        memset(dp, 0, 4*(n+1));
        memset(dpp, 0, 4*(n+1));
        for (int l = 1; l <= n; ++l) {
            dpp[0] = 1;
            for (int i = 0; i < n; ++i) {
                dp[i + 1] = dpp[i + 1];
                if (l <= i + 1 && num[i + 1 - l] != '0') {
                    if (i + 1 - 2 * l >= 0 && num.compare(i + 1 - 2 * l, l, num, i + 1 - l, l) <= 0)
                        dp[i + 1] = (dp[i + 1] + dp[i + 1 - l]) % mod;
                    else
                        dp[i + 1] = (dp[i + 1] + dpp[i + 1 - l]) % mod;
                }
            }
            swap(dp, dpp);
        }
        return dpp[n];
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
