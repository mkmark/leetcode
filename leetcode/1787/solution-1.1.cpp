/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 414 ms, faster than 86.79% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
Memory Usage: 22.4 MB, less than 61.32% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
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
    int min_num_count_max = INT32_MAX;

    int minChanges(vector<int> &nums, int k)
    {
        window_width = k;

        // num_count[ith of k][num] = count
        num_count.resize(k);
        int num_count_max[k];
        memset(num_count_max, 0, sizeof num_count_max);

        int nums_size = size(nums);

        int imk;
        for (int i = 0; i < nums_size; ++i)
        {
            imk=i%k;
            num_count_max[imk] = max(num_count_max[imk], ++num_count[imk][nums[i]]);
        }

        // situation 1 of 2 - one is not present
        int max_preserve_1 = 0;
        for (int i=0; i<k; ++i){
            max_preserve_1 += num_count_max[i];
            min_num_count_max = min(min_num_count_max, num_count_max[i]);
        }
        max_preserve_1 -= min_num_count_max;

        // situation 2 of 2 - all is present
        int dp[(k+1)<<10];
        memset(dp, -1, sizeof dp);

        int max_preserve_2 = dfs_max_preserve(dp, num_count_max, k, 0, 0);
        // int max_preserve_2 = 0;
        return nums_size - max(max_preserve_1, max_preserve_2);
    }

    int dfs_max_preserve(int *dp, int *num_count_max, int i, int j, int loss)
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
        for (auto &kv : num_count[i-1])
        {
            int new_loss = loss + num_count_max[i-1] - kv.second;
            if (new_loss>=min_num_count_max) {
                continue;
            }
            dp[(i<<10)+j] = max(
                dp[(i<<10)+j],
                dfs_max_preserve(dp, num_count_max, i - 1, j ^ kv.first, new_loss) + kv.second
            );
        }
        return dp[(i<<10)+j];
    }
};

const static auto initialize = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
