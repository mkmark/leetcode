/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 23 ms, faster than 100.00% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
Memory Usage: 14 MB, less than 89.62% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
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
    vector<unordered_map<int, int>> num_count;
    int max_preserved = 0;

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
        int min_num_count_max = INT32_MAX;
        for (int i=0; i<k; ++i){
            max_preserved += num_count_max[i];
            min_num_count_max = min(min_num_count_max, num_count_max[i]);
        }
        max_preserved -= min_num_count_max;

        // situation 2 of 2 - all is present
        int num_count_max_suffix[k];
        num_count_max_suffix[k-1] = num_count_max[k-1];
        for (int i=k-2; i >= 0 ; i--){
            num_count_max_suffix[i] = num_count_max_suffix[i+1] + num_count_max[i];
        }
        dfs_max_preserved(num_count_max_suffix, 0, 0, 0);
        return nums_size - max_preserved;
    }

    void dfs_max_preserved(int *num_count_max_suffix, int i, int j, int preserved)
    {
        if (i==window_width){
            if (j==0){
                max_preserved = max(max_preserved, preserved);
            }
        } else if (preserved + num_count_max_suffix[i] > max_preserved) {
            for (auto &kv : num_count[i])
            {   
                dfs_max_preserved(
                    num_count_max_suffix, 
                    i+1, 
                    j^kv.first, 
                    preserved+kv.second
                );
            }
        }
    }
};

const static auto initialize = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
