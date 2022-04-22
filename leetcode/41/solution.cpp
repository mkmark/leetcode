/*
author: mark@mkmark.net
time: O(n)
space: O(1)

Runtime: 121 ms, faster than 99.82% of C++ online submissions for First Missing Positive.
Memory Usage: 84.6 MB, less than 25.72% of C++ online submissions for First Missing Positive.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size = size(nums);
        for (int i = 0; i<nums_size; ++i){
            int j = nums[i];
            while (j>i && j<=nums_size){
                int new_j = nums[j-1];
                if (new_j == j){
                    break;
                }
                nums[j-1] = j;
                j = new_j;
            }
            if (j>0 && j<=i){
                nums[j-1] = j;
            }
        }
        for (int i = 0; i<nums_size; i){
            if (nums[i] != ++i){
                return i;
            }
        }
        return nums_size+1;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
