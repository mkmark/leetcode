/*
author: mark@mkmark.net
time: O(mn)
space: O(mn)

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Dungeon Game.
Memory Usage: 8.9 MB, less than 51.07% of C++ online submissions for Dungeon Game.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int min_health[201][201];
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = size(dungeon);
        int n = size(dungeon[0]);

        for (int i=0; i<m; ++i){
            fill_n(min_health[i], n, INT32_MAX);
        }

        int i = m-1;
        int j = n-1;

        int i_begin = m-1;
        int j_begin = n-1;

        min_health[i][j] = max(-dungeon[i][j]+1, 1);

        while (1){
            if (i) min_health[i-1][j] = max(min(min_health[i-1][j], min_health[i][j] - dungeon[i-1][j]), 1);
            if (j) min_health[i][j-1] = max(min(min_health[i][j-1], min_health[i][j] - dungeon[i][j-1]), 1);
            ++i;
            --j;
            if (i>m-1 || j<0) {
                if (i_begin>0){
                    i = --i_begin;
                    j = j_begin;
                } else if (j_begin > 0){
                    i = 0;
                    j = --j_begin;
                } else {
                    break;
                }
            }
        }

        return max(min_health[0][0], 1);
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
