/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime: 115 ms, faster than 99.89% of C++ online submissions for First Missing Positive.
Memory Usage: 85.6 MB, less than 24.16% of C++ online submissions for First Missing Positive.

reference: leetcode fastest solution
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size = size(nums);
        int seen_size = nums_size+1;
        vector<char> seen(seen_size);
        for(auto n:nums){
            if(n>0 && n<seen_size){
                seen[n-1]=true;
            }
        }
        for(int i=0;;i){
            if(seen[i++]==false){
                return i;
            }
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
