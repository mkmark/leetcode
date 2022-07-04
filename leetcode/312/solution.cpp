/*
author: mark@mkmark.net
time: O(n^2)
space: O(n^2)

Runtime: 215 ms, faster than 98.70% of C++ online submissions for Burst Balloons.
Memory Usage: 8.3 MB, less than 87.40% of C++ online submissions for Burst Balloons.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int dp[300][300];
    int n;
    int maxCoins(vector<int>& nums) {
        n = size(nums);
        for (int i=0; i<n; ++i) memset(dp[i], 0, n);
        return dfs_max_coins(0, n-1, nums);
    }

    int dfs_max_coins(int i, int j, vector<int>& nums){
        if (j<i) return 0;
        if (dp[i][j]) return dp[i][j];
        int dpij = 0;
        int l = i==0 ? 1 : nums[i-1];
        int r = j==n-1 ? 1 : nums[j+1];
        for (int k = i; k<=j; ++k){
            dpij = max(
                dpij,
                l*r*nums[k]+dfs_max_coins(i,k-1,nums)+dfs_max_coins(k+1,j,nums)
            );
        }
        return dp[i][j] = dpij;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
