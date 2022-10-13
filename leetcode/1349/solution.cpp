/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int m;
    int n;
    int res = 0;

    /// @brief 
    /// '#', 35, broken
    /// '.', 46, unoccupied
    /// '*', 42, occupied (extended)
    ///     <43, unavailable
    ///    >=43, available
    char dp_seats[8][8];

    int maxStudents(vector<vector<char>>& seats) {
        m = size(seats);
        n = size(seats[0]);
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                dp_seats[i][j] = seats[i][j];
            }
        }
        dfs(m-1, n-1, 0);
        return res;
    }

    void dfs(int i, int j, int count){
        res = max(res, count);
        if (j==-1){
            if (i==0){
                return;
            } else {
                j = n-1;
                --i;
            }
        }
        char a = 0;
        char b = 0;
        char c = 0;
        char d = 0;
        if (dp_seats[i][j] >= 43){
            // dp_seats[i][j] = '*';
            if (i){
                if (j) {
                    a = dp_seats[i-1][j-1];
                    dp_seats[i-1][j-1] = '*';
                }
                if (j<n-1) {
                    b = dp_seats[i-1][j+1];
                    dp_seats[i-1][j+1] = '*';
                }
            }
            if (j) {
                c = dp_seats[i][j-1];
                dp_seats[i][j-1] = '*';
            }
            if (j<n-1) {
                d = dp_seats[i][j+1];
                dp_seats[i][j+1] = '*';
            }
            dfs(i, j-1, count+1);
            // dp_seats[i][j] = '.';
            if (a) dp_seats[i-1][j-1] = a;
            if (b) dp_seats[i-1][j+1] = b;
            if (c) dp_seats[i][j-1] = c;
            if (d) dp_seats[i][j+1] = d;
        }

        dfs(i, j-1, count);
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
