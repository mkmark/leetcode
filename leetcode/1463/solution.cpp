/*
author: mark@mkmark.net
time: O(mn)
space: O(mmn^2)

Runtime: 34 ms, faster than 95.72% of C++ online submissions for Cherry Pickup II.
Memory Usage: 10.3 MB, less than 68.81% of C++ online submissions for Cherry Pickup II.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // i, j1, j2
    int dp[70][70][70];
    char seen[70][70][70]{};
    int m, n;

    int cherryPickup(vector<vector<int>>& grid) {
        m = size(grid);
        n = size(grid[0]);

        return dfs_max_sum(grid, 0, 0, n-1);
    }

    int dfs_max_sum(vector<vector<int>>& grid, int i, int j1, int j2){
        if (i == m || j1 < 0 || j2 < 0 || j1 == n || j2 == n ){
            return 0;
        } else if (dp[i][j1][j2]){
            return dp[i][j1][j2];
        } else {
            int max_sum = 0;
            int sum;
            for (int k1=-1; k1<=1; ++k1){
                for (int k2=-1; k2<=1; ++k2){
                    sum = dfs_max_sum(grid, i+1, j1+k1, j2+k2);
                    max_sum = max(max_sum, sum);
                }
            }
            max_sum += grid[i][j1];
            if (j1 != j2){
                max_sum += grid[i][j2];
            }
            dp[i][j1][j2] = max_sum;
            seen[i][j1][j2] = true;
            return max_sum;
        }
    }
};
const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
