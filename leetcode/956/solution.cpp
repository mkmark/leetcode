/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 143 ms, faster than 45.67% of C++ online submissions for Tallest Billboard.
Memory Usage: 45.8 MB, less than 32.54% of C++ online submissions for Tallest Billboard.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int n;
    int max_pos_diff;
    // int dp[1000][10001];
    int tallestBillboard(vector<int>& rods) {
        n = size(rods);
        max_pos_diff = min(5000, accumulate(all(rods), 0));
        vvi dp(n+1, vi(max_pos_diff*2+1));
        return dfs_max_height(0, 0, 0, rods, dp);
    }

    int dfs_max_height(int i, int diff, int height, vector<int>& rods, vvi& dp){
        if (dp[i][diff+max_pos_diff]) return height + dp[i][diff+max_pos_diff];
        if (i==n){
            if (diff == 0) return height; else return -5001;
        } else {
            dp[i][diff+max_pos_diff] = max(
                max(
                    dfs_max_height(i+1, diff+rods[i], height+rods[i], rods, dp),
                    dfs_max_height(i+1, diff-rods[i], height, rods, dp)
                ),
                dfs_max_height(i+1, diff, height, rods, dp)
            ) - height;
            return dp[i][diff+max_pos_diff] + height;
        } 
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
