/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 

dp
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int num_size;
    int numberOfCombinations(string& num) {
        if (num[0] == 0) return 0;
        num_size = size(num);
        vvi dp(num_size, vi(num_size, -1));
        int res=0;
        for (int i=0; i<num_size; ++i){
            res += dfs_comb(0, i, num, dp);
            res %= 1000000007;
        }
        return res;
    }

    int get_min_nxt_end(int& cur_begin, int& cur_end, string& num){
        if (cur_end == num_size-1) return 0;
        int nxt_i = cur_end+1;
        if (num[nxt_i] == 0) return 0;
        int cur_i = cur_begin;
        if ((num_size-1-nxt_i)<(cur_end-cur_begin)) return 0;
        while (cur_i<=cur_end-1 && nxt_i<num_size-1 && num[cur_i] == num[nxt_i]){
            ++cur_i;
            ++nxt_i;
        };
        if (num[cur_i]<=num[nxt_i]){
            return cur_end*2+1-cur_begin;
        } else {
            return cur_end*2+2-cur_begin;
        }
    }

    int dfs_comb(int cur_begin, int cur_end, string& num, vvi& dp){
        if (dp[cur_begin][cur_end] > -1) return dp[cur_begin][cur_end];
        if (num[cur_begin]=='0') return dp[cur_begin][cur_end]=0;
        if (cur_end == num_size-1) return dp[cur_begin][cur_end] = 1;

        int min_nxt_end = get_min_nxt_end(cur_begin, cur_end, num);
        if (min_nxt_end){
            dp[cur_begin][cur_end] = 0;
            for (int i=min_nxt_end; i<num_size; ++i){
                dp[cur_begin][cur_end] += dfs_comb(cur_end+1, i, num, dp);
                dp[cur_begin][cur_end] %= 1000000007;
            }
            return dp[cur_begin][cur_end];
        } else {
            return dp[cur_begin][cur_end] = 0;
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
