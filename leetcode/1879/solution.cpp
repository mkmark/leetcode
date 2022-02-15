/*
author: mark@mkmark.net
time: O(!n)
space: O(1)

Runtime: 16 ms, faster than 95.58% of C++ online submissions for Minimum XOR Sum of Two Arrays.
Memory Usage: 8.9 MB, less than 92.77% of C++ online submissions for Minimum XOR Sum of Two Arrays.

reference: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/discuss/1238641/Bit-Mask
reference: https://en.wikipedia.org/wiki/Derangement
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    static const int MAX = 1<<14;
    int dp[MAX];
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        for (int i=0;i<MAX;++i){
            dp[i] = INT32_MAX;
        }
        return dfs_min_xor_sum(nums1, nums2, 0, 0);
    }

    /**
     * @brief used_j_mask indicates numbers that have been used in nums2, 
     * the count of used_j_mask (x) corresponds to the first x numbers that that been used in nums1,
     * so there's no need to mem used_i_mask
     * 
     * @param nums1 
     * @param nums2 
     * @param i nums1[i]
     * @param used_j_mask
     * @return int 
     */
    int dfs_min_xor_sum(
        vector<int>& nums1, 
        vector<int>& nums2,
        int i,
        int used_j_mask
    ){
        int n = nums1.size();
        if (i>=n){
            return 0;
        }
        if (dp[used_j_mask] != INT32_MAX){
            return dp[used_j_mask];
        }
        int res = INT32_MAX;
        for (int j=0; j<n; ++j){
            // j used, skip
            if (used_j_mask & (1<<j)){
                continue;
            }
            res = min(
                res,
                (nums1[i]^nums2[j]) + dfs_min_xor_sum(
                    nums1, 
                    nums2, 
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
