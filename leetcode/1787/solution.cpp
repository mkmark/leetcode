/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 553 ms, faster than 89.47% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
Memory Usage: 22.5 MB, less than 87.72% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution
{
public:
    int window_width;
    vector<map<int, int>> num_count;
    int max_m = 1;
    int minChanges(vector<int> &nums, int k)
    {
        window_width = k;

        // dp[first i of k][xor value] = max preserved
        // vector<int[1024]> dp(k + 1);
        // for (int i=0; i<k+1; ++i){
        //     fill_n(dp[i], 1024, -1);
        // }
        int dp[(k+1)<<10];
        memset(dp, -1, sizeof dp);

        // num_count[ith of k][num] = count
        num_count.resize(k);

        int nums_size = size(nums);

        int max_num = INT32_MIN;
        for (int i = 0; i < nums_size; ++i)
        {
            ++num_count[i % k][nums[i]];
            max_num = max(max_num, nums[i]);
        }
        // 5^3=6, so max_num is not safe. Though it pass all the tests, it's not safe.
        while(max_m < max_num) max_m<<=1;
        max_m = min(max_m+1, 1024);

        int max_preserve = dfs_max_preserve(dp, k, 0, false);
        return nums_size - max_preserve;
    }

    int dfs_max_preserve(int *dp, int i, int j, bool guessed)
    {
        if (dp[(i<<10)+j] != -1)
            return dp[(i<<10)+j];
        if (i == 0)
        {
            if (j == 0)
            {
                return dp[0] = 0;
            }
            else
            {
                // -2001 is suficient
                return dp[j] = -2001;
            }
        }
        int dpij = -1;
        for (auto &kv : num_count[i - 1])
        {
            dpij = max(dpij, dfs_max_preserve(dp, i - 1, j ^ kv.first, guessed) + kv.second);
        }
        if (!guessed)
        {
            for (int m = 0; m < max_m; ++m)
            {
                // to remove keys from kv costs more
                dpij = max(dpij, dfs_max_preserve(dp, i - 1, j ^ m, true));
            }
        }
        return dp[(i<<10)+j] = dpij;
    }
};

const static auto initialize = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
