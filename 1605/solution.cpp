#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include <numeric>      // std::iota

class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& sum_row, std::vector<int>& sum_col) {
        int sum_row_size = sum_row.size();
        int sum_col_size = sum_col.size();
        int sum_all_size = sum_row_size + sum_col_size;

        // sort index of sum_row
        std::vector<int> idx_sum_row(sum_row_size);
        std::iota(idx_sum_row.begin(),idx_sum_row.end(),0);
        sort(idx_sum_row.begin(), idx_sum_row.end(), [&](int i,int j){return sum_row[i]<sum_row[j];});

        // sort index of sum_col
        std::vector<int> idx_sum_col(sum_col_size);
        std::iota(idx_sum_col.begin(),idx_sum_col.end(),0);
        sort(idx_sum_col.begin(), idx_sum_col.end(), [&](int i,int j){return sum_col[i]<sum_col[j];});

        // initialize output matrix
        int m = sum_row_size;
        int n = sum_col_size;
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));

        // tactics
        int i = 0;
        int j = 0;
        while (i<m && j<n){
            int cur_row_idx = idx_sum_row[i];
            int cur_col_idx = idx_sum_col[j];
            int cur_sum_row = sum_row[cur_row_idx];
            int cur_sum_col = sum_col[cur_col_idx];
            if (cur_sum_row <= cur_sum_col){
                int num_to_fill = cur_sum_row;
                matrix[cur_row_idx][cur_col_idx] = num_to_fill;
                sum_row[cur_row_idx] = 0;
                sum_col[cur_col_idx] -= num_to_fill;
                ++i;
            } else {
                int num_to_fill = cur_sum_col;
                matrix[cur_row_idx][cur_col_idx] = num_to_fill;
                sum_col[cur_col_idx] = 0;
                sum_row[cur_row_idx] -= num_to_fill;
                ++j;
            }
        }

        return matrix;
    }
};
