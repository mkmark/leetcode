/*
author: mark@mkmark.net
time: O(nm^2)
space: O(m)

Runtime: 10 ms, faster than 100.00% of C++ online submissions for Delete Columns to Make Sorted III.
Memory Usage: 10.3 MB, less than 51.49% of C++ online submissions for Delete Columns to Make Sorted III.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int dp[100];
    int minDeletionSize(vector<string>& strs) {
        int n = size(strs);
        int m = size(strs[0]);
        fill_n(dp, m, 1);
        int k;
        int dp_max = 0;
        for (int i=0; i<m; ++i){
            for (int j=i+1; j<m; ++j){
                for (k=0; k<n; ++k){
                    if (strs[k][i]>strs[k][j]){
                        break;
                    }
                }
                if (k==n){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
            dp_max = max(dp_max, dp[i]);
        }
        return m-dp_max;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
