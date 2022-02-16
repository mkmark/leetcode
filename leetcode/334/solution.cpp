/*
author: mark@mkmark.net
time: O(n)
space: O(1)

Runtime: 40 ms, faster than 99.91% of C++ online submissions for Increasing Triplet Subsequence.
Memory Usage: 61.4 MB, less than 99.02% of C++ online submissions for Increasing Triplet Subsequence.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return false;
        int a = nums[0];
        int b;
        int a_cand= INT32_MAX;
        int count = 1;
        for (int i=1; i<n; ++i){
            if (count == 2){
                if (nums[i] > b){
                    return true;
                } else if (nums[i] > a){
                    b = nums[i];
                } else if (nums[i] > a_cand){
                    a = a_cand;
                    b = nums[i];
                    a_cand = INT32_MAX;
                } else {
                    a_cand = nums[i];
                }
            } else if (count == 1){
                if (nums[i] > a){
                    b = nums[i];
                    count = 2;
                } else {
                    a = nums[i];
                }
            }
        }
        return false;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
