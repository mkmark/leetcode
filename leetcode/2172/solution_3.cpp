/*
author: mark@mkmark.net
time: O(n^3)
space: O()

Runtime: 4 ms, faster than 99.61% of C++ online submissions for Maximum AND Sum of Array.
Memory Usage: 8.7 MB, less than 95.62% of C++ online submissions for Maximum AND Sum of Array.

reference: leetcode 4ms solution
*/

// hungarian

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    #include "hungarian.h"
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        vector<vector<int>> cost(2 * numSlots, vector<int>(2 * numSlots));
        for (int i = 0; i < 2 * numSlots; ++i) {
            for (int j = 0; j < 2 * numSlots; ++j) {
                if (i >= nums.size()){
                    cost[i][j] = 0;
                } else {
                    cost[i][j] = - ((nums[i]) & (j/2+1));
                }
                
            }
        }
        return -hungarian(cost).first;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
