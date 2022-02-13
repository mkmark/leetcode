// Runtime: 76 ms, faster than 100.00% of C++ online submissions for Ways to Make a Fair Array.
// Memory Usage: 98.7 MB, less than 41.14% of C++ online submissions for Ways to Make a Fair Array.

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int sum_odd = 0;
        int sum_even = 0;
        // vector<int> sum_odds(n, 0);
        // vector<int> sum_evens(n, 0);
        // for (int i=0; i<n; ++i){
        //     // odd
        //     if (i%2){
        //         sum_odd += nums[i];
        //     // even
        //     } else {
        //         sum_even += nums[i];
        //     }
        //     sum_odds[i] = sum_odd;
        //     sum_evens[i] = sum_even;
        // }
        //
        // int res_count = 0;
        // for (int i=0; i<n; ++i){
        //     // odd
        //     if (i%2){
        //         if (sum_odds[i] - nums[i] + sum_even - sum_evens[i] == sum_evens[i] + sum_odd - sum_odds[i]){
        //             ++res_count;
        //         }
        //     // even
        //     } else {
        //         if (sum_odds[i] + sum_even - sum_evens[i] == sum_evens[i] - nums[i] + sum_odd - sum_odds[i]){
        //             ++res_count;
        //         }
        //     }
        // }
        // return res_count;

        // same as above but faster
        vector<int> res_sum_odds_even(n, 0);
        for (int i=0; i<n; ++i){
            // odd
            if (i%2){
                sum_odd += nums[i];
                res_sum_odds_even[i] = (sum_odd - sum_even) * 2 - nums[i];
            // even
            } else {
                sum_even += nums[i];
                res_sum_odds_even[i] = (sum_odd - sum_even) * 2 + nums[i];
            }
        }

        int res_count = 0;
        int target = sum_odd - sum_even;
        for (int i=0; i<n; ++i){
            if (res_sum_odds_even[i] == target){
                ++res_count;
            }
        }
        return res_count;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
