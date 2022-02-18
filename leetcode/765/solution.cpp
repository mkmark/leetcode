/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Couples Holding Hands.
Memory Usage: 7.6 MB, less than 23.02% of C++ online submissions for Couples Holding Hands.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        int n2 = n*2;
        vector<int[2]> cp_idx_2_row_idx(n); 
        for (int i=0; i<n2; ++i){
            cp_idx_2_row_idx[row[i]/2][row[i]%2] = i;
        }
        int swap_count = 0;
        dfs_swap(1, swap_count, row, cp_idx_2_row_idx);
        return swap_count;
    }
    void dfs_swap(int i, int& swap_count, vector<int>& row, vector<int[2]>& cp_idx_2_row_idx){
        int n2 = row.size();
        if (i > n2){
            return;
        }
        auto left_cp_idx = row[i-1]/2;
        auto left_cp_sex = row[i-1]%2;
        auto right_cp_idx = row[i]/2;
        auto right_cp_sex = row[i]%2;
        if (right_cp_idx == left_cp_idx){
            dfs_swap(i+2, swap_count, row, cp_idx_2_row_idx);
            return;
        }
        swap(row[i], row[cp_idx_2_row_idx[left_cp_idx][1-left_cp_sex]]);
        swap(cp_idx_2_row_idx[right_cp_idx][right_cp_sex], cp_idx_2_row_idx[left_cp_idx][1-left_cp_sex]);
        ++swap_count;
        dfs_swap(i+2, swap_count, row, cp_idx_2_row_idx);
        return;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
