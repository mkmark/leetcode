/*
author: mark@mkmark.net
time: O(P_m^n)
space: O(3^n)

Runtime: 28 ms, faster than 90.55% of C++ online submissions for Maximum AND Sum of Array.
Memory Usage: 8 MB, less than 98.05% of C++ online submissions for Maximum AND Sum of Array.
*/

// base 3

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    // 3^9
    static const int MAX_SLOT_MASK = 19683;
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
        if (dp[mask] != -1){
            return dp[mask];
        }
        int res = 0;
        for (int j=0; j<numSlots; ++j){
            int jth_mask = get_ith(j, mask, 3);
            // skip if full
            if (jth_mask == 2) continue;
            int mask_i = add_ith(j, mask, 3, 1);
            res = max(
                res,
                (nums[i] & (j+1)) + dfs_max_and_sum(
                    nums,
                    numSlots,
                    mask_i,
                    i+1
                )
            );
        }
        return dp[mask] = res;
    }

    /**
     * @brief integer power
     * 
     * @param x base
     * @param p power
     * @return int 
     */
    int int_pow(int x, int p) {
        int res = 1;
        for (int i=1; i<=p; ++i){
            res *= x;
        }
        return res;
    }

    /**
     * @brief get the ith single mask
     * 
     * @param i position
     * @param dec decimal mask
     * @param base 
     * @return int 
     */
    inline int get_ith(int i, int dec, int base){
        dec /= int_pow(base, i);
        return dec % base;
    }

    /**
     * @brief add the ith single mask
     * 
     * @param i position
     * @param dec decimal mask
     * @param base 
     * @param new single mask to set
     * @param ori original single mask
     * @return int 
     */
    inline int add_ith(int i, int dec, int base, int to_add){
        return dec + to_add * int_pow(base, i);
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
