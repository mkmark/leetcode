/*
author: mark@mkmark.net
time: O()
space: O()

Runtime 4 ms Beats 91.1%
Memory 11.5 MB Beats 24.87%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/// @brief dp_max_students[i][status of i] = max students to be deployed later
uint8_t dp_max_students[8][8][65536];
/// @brief bit 1 means occupied 
uint16_t initial_status[8];
uint8_t m;
uint8_t n;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) { 
        m = size(seats);
        n = size(seats[0]);
        int tmp = 1<<(n+8);
        for (int i=0; i<m; ++i){
            initial_status[i] = 0;
            for (int j=0; j<n; ++j){
                initial_status[i] |= (seats[i][j]=='#')<<j;
                // fill_n(dp_max_students[i][j], tmp, -1);
                memset(dp_max_students[i][j], -1, tmp);
            }
        }
        return dfs_max_students(0, 0, (initial_status[0]<<8) + (initial_status[1]));
    }

    /// @brief 
    /// @param i 
    /// @param j 
    /// @param status status & 1<<(j+8) is current line, status & 1<<j is next line
    /// @return 
    int dfs_max_students(uint8_t i, uint8_t j, uint16_t status){
        if (j>=n){
            if (i==m-1){
                return 0;
            } else {
                j = 0;
                ++i;
                status <<= 8;
                if (i<m-1){
                    status |= initial_status[i+1];
                }
            }
        }

        if (dp_max_students[i][j][status] <= 64){
            return dp_max_students[i][j][status];
        }

        if ((status & (1 << (j+8))) == 0){
            int new_status = status;
            if (i<m-1){
                if (j) {
                    new_status |= 1<<j-1;
                }
                if (j<n-1) {
                    new_status |= 1<<j+1;
                }
            }
            if (j) {
                new_status |= 1<<j+7;
            }
            if (j<n-1) {
                new_status |= 1<<j+9;
            }

            return dp_max_students[i][j][status] = max(
                dfs_max_students(i, j+1, status),
                dfs_max_students(i, j+2, new_status) + 1
            );
        } else {
            return dp_max_students[i][j][status] = dfs_max_students(i, j+1, status);
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
