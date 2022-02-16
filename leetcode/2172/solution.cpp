/*
author: mark@mkmark.net
time: O(P_m^n)
space: O(2^m)

Runtime: 40 ms, faster than 83.36% of C++ online submissions for Maximum AND Sum of Array.
Memory Usage: 9.2 MB, less than 89.61% of C++ online submissions for Maximum AND Sum of Array.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    static const int MAX_SLOT_MASK = 1<<18;
    // dp[mask_slots]
    int dp[MAX_SLOT_MASK];
    int maximumANDSum(vector<int>& nums, int numSlots) {
        for (int i=0; i<MAX_SLOT_MASK; ++i){
            dp[i] = -1;
        }
        int mask = 0;
        return dfs_max_and_sum(
            nums,
            numSlots,
            mask,
            0
        );
    }

    int dfs_max_and_sum(
        vector<int>& nums,
        int& numSlots,
        int& mask,
        int i
    ){
        if (i==nums.size()){
            return 0;
        }
        if (dp[mask]!=-1){
            return dp[mask];
        }
        int res = 0;
        for (int j=0; j<2*numSlots; ++j){
            // skip if full
            if (mask & (1<<j)) continue;
            // skip pos 2 without filling in pos 1
            if ((j%2) && (!(mask & (1<<(j-1))))) continue;
            int mask_i = mask | (1<<j);
            res = max(
                res,
                (nums[i] & (j/2+1)) + dfs_max_and_sum(
                    nums,
                    numSlots,
                    mask_i,
                    i+1
                )
            );
        }
        return dp[mask] = res;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
