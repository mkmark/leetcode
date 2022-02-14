/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 392 ms, faster than 97.46% of C++ online submissions for Stamping the Grid.
Memory Usage: 169.8 MB, less than 82.24% of C++ online submissions for Stamping the Grid.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    vector<vector<int>> accumulated(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                res[i+1][j+1] = res[i+1][j] + res[i][j+1] - res[i][j] + mat[i][j];
            }
        }
        return res;
    }
    int sum2d(vector<vector<int>> &accumulated, int b, int l, int t, int r) {
        return accumulated[b][r] - accumulated[b][l] - accumulated[t][r] + accumulated[t][l];
    }
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int m = grid.size();
        int n = grid[0].size();
        if (m<h || n<w){
            for (int i=0; i<m; ++i){
                for (int j=0; j<n; ++j){
                    if (grid[i][j] == 0){
                        return false;
                    }
                }
            }
            return true;
        }

        vector<vector<int>> stamp(m-h+1, vector<int>(n-w+1));
        auto acc = accumulated(grid);
        for (int i=0; i<=m-h; ++i){
            for (int j=0; j<=n-w; ++j){
                stamp[i][j] = sum2d(acc, i, j, i+h, j+w) == 0;
            }
        }
        auto acc2 = accumulated(stamp);
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j] == 0 && sum2d(acc2, max(0, i-h+1), max(0, j-w+1), min(m-h+1, i+1), min(n-w+1, j+1)) == 0){
                    return false;
                }
            }
        }
        return true;
    }
};
// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
