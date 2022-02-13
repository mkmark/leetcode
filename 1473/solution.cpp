// Runtime: 76 ms, faster than 80.42% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.
// Memory Usage: 10.8 MB, less than 64.24% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.

// https://leetcode.com/problems/paint-house-iii/discuss/?currentPage=1&orderBy=most_votes&query=

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        auto res = dfs(houses, cost, 0, target, 0);
        return res > 1000000 ? -1 : res;
    }
    // dp[index of house][target][last_color]
    int dp[101][101][21] = {};
    /**
     *  @brief 
     *  @param i index of current house
     *  @param target_rem remaning target, i.e numbers of community available after i
     *  @param last_color color of last house
     */
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int target_rem, int last_color) {
        if (target_rem<0 && i < houses.size())
        // impossible
            return 1000001;
        else if (i >= houses.size())
        // if i reach end
            if (target_rem == 0)
                // no further cost
                return 0;
            else
                // impossible
                return 1000001;
        else if (houses[i] != 0)
        // painted last year.
            return dfs(houses, cost, i + 1, target_rem - (last_color != houses[i]), houses[i]);      
        else if (dp[i][target_rem][last_color])
        // cached
            return dp[i][target_rem][last_color];
            
        auto res = 1000001;
        for (auto color = 1; color <= cost[i].size(); ++color) {
            res = min(
                res, 
                cost[i][color - 1] + dfs(
                    houses, 
                    cost, 
                    i + 1, 
                    target_rem - (last_color != color), 
                    color
                )
            );
        }            
        return dp[i][target_rem][last_color] = res;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);