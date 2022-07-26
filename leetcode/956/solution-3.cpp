/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 17 ms, faster than 99.70% of C++ online submissions for Tallest Billboard.
Memory Usage: 8.1 MB, less than 95.82% of C++ online submissions for Tallest Billboard.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int n;
    // int max_pos_diff;
    int dp[21][2501] = {};
    int tallestBillboard(vector<int>& rods) {
        n = size(rods);
        // max_pos_diff = accumulate(all(rods), 0);
        sort(all(rods));
        // vvi dp(n+1, vi(max_pos_diff+1));
        return dfs_max_height(0, 0, 0, rods);
    }

    int dfs_max_height(int i, int a, int b, vector<int>& rods){
        int diff = abs(a-b);
        if (diff > 2500) return -5001;
        int height = max(a,b);
        if (dp[i][diff]) return height + dp[i][diff];
        if (i==n){
            if (diff == 0) return height; else return -5001;
        } else {
            dp[i][diff] = max(
                max(
                    dfs_max_height(i+1, a+rods[i], b, rods),
                    dfs_max_height(i+1, a, b+rods[i], rods)
                ),
                dfs_max_height(i+1, a, b, rods)
            ) - height;
            return dp[i][diff] + height;
        } 
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
