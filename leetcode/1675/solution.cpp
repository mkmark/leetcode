/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 599 ms, faster than 23.73% of C++ online submissions for Minimize Deviation in Array.
Memory Usage: 56.8 MB, less than 96.19% of C++ online submissions for Minimize Deviation in Array.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int nums_min = INT_MAX;
        priority_queue<int> pq;
        for (int i=0; i<size(nums); ++i){
            if (nums[i]%2){
                nums[i]*=2;
                pq.push(nums[i]);
                nums_min = min(nums_min, nums[i]);
            }
            else {
                pq.push(nums[i]);
                nums_min = min(nums_min, nums[i]);
            }
        }
        int min_diff = INT_MAX;
        int tmp;
        while (pq.top()%2 == 0){
            tmp = pq.top();
            min_diff = min(min_diff, tmp - nums_min);
            tmp/=2;
            pq.push(tmp);
            nums_min = min(nums_min, tmp);
            pq.pop();
        }
        return min(min_diff, pq.top() - nums_min);
    }
};
const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
