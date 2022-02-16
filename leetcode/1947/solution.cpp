/*
author: mark@mkmark.net
time: O(P_m^m)
space: O(2^m)

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Compatibility Score Sum.
Memory Usage: 10.2 MB, less than 28.86% of C++ online submissions for Maximum Compatibility Score Sum.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    static const int MAX = 1<<8;
    int dp[MAX];
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();

        int students_bit[8];
        int mentors_bit[8];

        for (int i=0; i<m; ++i){
            students_bit[i] = vec_to_int(students[i]);
            mentors_bit[i] = vec_to_int(mentors[i]);
        }

        int compatibility[8][8];
        for (int i=0; i<m; ++i){
            for (int j=0; j<m; ++j){
                compatibility[i][j] = count_bin_0(students_bit[i] ^ mentors_bit[j], n);
            }
        }

        for (int i=0;i<(1<<m);++i){
            dp[i] = 0;
        }

        return dfs_max_sum(compatibility, m, 0, 0);
    }

    inline int vec_to_int(vector<int> v){
        int res = 0;
        for (int i=0; i<v.size(); ++i){
            res |= (v[i]<<i);
        }
        return res;
    }

    inline int count_bin_0(int num, int n){
        int count = 0;
        for (int i=0; i<n; ++i){
            count += ((num & (1<<i)) == 0);
        }
        return count;
    }

    int dfs_max_sum(
        int compatibility[8][8],
        int& m,
        int i, 
        int used_j_mask
    ){
        if (i>=m){
            return 0;
        }
        if (dp[used_j_mask] != 0){
            return dp[used_j_mask];
        }
        int res = 0;
        for (int j=0; j<m; ++j){
            // j used, skip
            if (used_j_mask & (1<<j)){
                continue;
            }
            res = max(
                res,
                compatibility[i][j] + dfs_max_sum(
                    compatibility, 
                    m, 
                    i+1,
                    used_j_mask | (1<<j)
                )
            );
        }
        return dp[used_j_mask] = res;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
