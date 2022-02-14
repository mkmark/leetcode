/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 456 ms, faster than 94.25% of C++ online submissions for Stamping the Grid.
Memory Usage: 197.5 MB, less than 52.54% of C++ online submissions for Stamping the Grid.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();
        if (m<stampHeight || n<stampWidth){
            for (int i=0; i<m; ++i){
                for (int j=0; j<n; ++j){
                    if (grid[i][j] == 0){
                        return false;
                    }
                }
            }
            return true;
        }

        vector<vector<int>> status(m, vector<int>(n, 0));

        vector<vector<int>> summed(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m; ++i){
            summed[i+1] = sum_vec(grid[i]);
            for (int j=0; j<=n; ++j){
                summed[i+1][j] += summed[i][j];
            }
        }

        int sum;
        int x_marked;
        vector<vector<int>> rectangles;
        int t;
        int b;
        int l;
        int r;

        for (int i=0; i<=m-stampHeight; ++i){
            x_marked = 0;
            for (int j=0; j<=n-stampWidth; ++j){
                t = i;
                b = i+stampHeight;
                l = j;
                r = j+stampWidth;
                // for (int p=t;p<b;++p){
                //     for (int q=l;q<r;++q){
                //         sum += grid[p][q];
                //     }
                // }
                bool need_full_update;
                sum = summed[b][r] - summed[b][l] - summed[t][r] + summed[t][l];
                if (sum == 0){
                    need_full_update = false;
                    for (int q=max(l,x_marked);q<r;++q){
                        if (b>1 && status[b-2][q]==0){
                            need_full_update = true;
                            break;
                        }
                    }
                    if (need_full_update){
                        for (int p=i;p<b;++p){
                            for (int q=max(l,x_marked);q<r;++q){
                                status[p][q] = 1;
                            }
                        }
                    } else {
                        for (int q=max(l,x_marked);q<r;++q){
                            status[b-1][q] = 1;
                        }
                    }
                    x_marked = r;
                }
            }
        }

        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j] == 0 && status[i][j] != 1){
                    return false;
                }
            }
        }
        return true;
    }

    inline vector<int> sum_vec(vector<int>& vec){
        int n = vec.size();
        vector<int> summed(n+1);
        int sum_num = 0;
        summed[0] = 0;
        for (int i=0; i<n; ++i){
            sum_num += vec[i];
            summed[i+1] =sum_num;
        }
        return summed;
    }
};
// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
