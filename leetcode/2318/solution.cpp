/*
author: mark@mkmark.net
time: O(n)
space: O(1)

Runtime: 29 ms, faster than 98.37% of C++ online submissions for Number of Distinct Roll Sequences.
Memory Usage: 6 MB, less than 97.65% of C++ online submissions for Number of Distinct Roll Sequences.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    /// A_i[pre][cur] = count arrangements to get to current position
    // int A_i[6][6] = {
    //     {0,1,1,1,1,1},
    //     {1,0,1,0,1,0},
    //     {1,1,0,1,1,0},
    //     {1,0,1,0,1,0},
    //     {1,1,1,1,0,1},
    //     {1,0,0,0,1,0},
    // };
    /// A_{i+1}=J*A_i-A_i^T, then set some value to 0
    /// where J is all one matrix
    // int A_{i+1}[6][6] = {
    //     {0,4,4,4,4,4},
    //     {2,0,2,0,2,0},
    //     {3,3,0,3,3,0},
    //     {2,0,2,0,2,0},
    //     {4,4,4,4,0,4},
    //     {1,0,0,0,1,0},
    // }

    int distinctSequences(int n) {
        if (n==1) {return 6;}
        int a[2][6][6] = {
            {
                {0,1,1,1,1,1},
                {1,0,1,0,1,0},
                {1,1,0,1,1,0},
                {1,0,1,0,1,0},
                {1,1,1,1,0,1},
                {1,0,0,0,1,0},
            },
            {
                {},
                {},
                {},
                {},
                {},
                {},
            }
        };

        int col_sum;
        int pre = 0;
        int cur = 1;
        const int modulo = 1e9+7;
        for (int n_i = 2; n_i<n; ++n_i){
            for (int j = 0; j<6; ++j){
                col_sum = 0;
                /// J*A
                for (int i = 0; i<6; ++i){
                    col_sum += a[pre][i][j];
                    col_sum %= modulo;
                }
                /// -A_i^T
                for (int i = 0; i<6; ++i){
                    if (a[pre][i][j]) a[cur][j][i] = (col_sum+modulo - a[pre][i][j]) % modulo;
                }
            }
            pre=1-pre;
            cur=1-cur;
        }
        int sum = 0;
        for (int j = 0; j<6; ++j){
            for (int i = 0; i<6; ++i){
                sum += a[pre][j][i];
                sum %= modulo;
            }
        }
        return sum;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
