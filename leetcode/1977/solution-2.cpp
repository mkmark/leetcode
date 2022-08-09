/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: tle
Memory Usage: 

dfs + dp + sum dp
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int n;
    /// dp[i][j] = sum(dp[j+1][2j-i .. n]), if flag
    ///            sum(dp[j+1][2j-i+1 .. n]), otherwise

    /// sumdp[i][j] = sum(dp[i][j .. n]), j>i
    /// dp[i][j] = sumdp[j+1][n] - sumdp[j+1][2j-i], if flag
    ///            sumdp[j+1][n] - sumdp[j+1][2j-i+1], otherwise
    vvi * ptr_dp;
    vvi * ptr_dpsum;
    vi * ptr_dpsum_caled;
    string * ptr_num;
    int numberOfCombinations(string& num) {
        if (num[0] == 0) return 0;
        ptr_num = & num;
        n = size(num);
        vvi dp(n, vi(n, -1));
        ptr_dp = & dp;
        vvi dpsum(n, vi(n+1));
        ptr_dpsum = & dpsum;
        vi dpsum_caled(n, n);
        ptr_dpsum_caled = & dpsum_caled;
        int res=0;
        for (int i=0; i<n; ++i){
            res += dfs_comb(0, i);
            res %= 1000000007;
        }
        return res;
    }

    int get_min_nxt_end(int& l, int& r){
        if (r == n-1) return 0;
        int nxt_i = r+1;
        int cur_i = l;
        if ((n-1-nxt_i)<(r-l)) return 0;
        while (cur_i<=r-1 && nxt_i<n-1 && (*ptr_num)[cur_i] == (*ptr_num)[nxt_i]){
            ++cur_i;
            ++nxt_i;
        };
        if ((*ptr_num)[cur_i]<=(*ptr_num)[nxt_i]){
            return r*2+1-l;
        } else {
            return r*2+2-l;
        }
    }

    /**
     * @brief 
     * 
     * @param l current begin
     * @param r current rbegin
     * @param num 
     * @param dp 
     * @return int 
     */
    int dfs_comb(int l, int r){
        if ((*ptr_dp)[l][r] > -1) return (*ptr_dp)[l][r];
        if ((*ptr_num)[l]=='0') return (*ptr_dp)[l][r]=0;
        if (r == n-1) return (*ptr_dp)[l][r] = 1;

        int min_nxt_end = get_min_nxt_end(l, r);
        if (min_nxt_end){
            if (min_nxt_end < (*ptr_dpsum_caled)[r+1]){
                for (int i=(*ptr_dpsum_caled)[r+1]-1; i>=min_nxt_end; --i){
                    (*ptr_dpsum)[r+1][i] = (*ptr_dpsum)[r+1][i+1] + dfs_comb(r+1, i);
                    (*ptr_dpsum)[r+1][i] %= 1000000007;
                }
                (*ptr_dpsum_caled)[r+1] = min_nxt_end;
            }
            (*ptr_dp)[l][r] = (*ptr_dpsum)[r+1][min_nxt_end];
            (*ptr_dp)[l][r] += 1000000007;
            (*ptr_dp)[l][r] %= 1000000007;
            return (*ptr_dp)[l][r];
        } else {
            return (*ptr_dp)[l][r] = 0;
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
