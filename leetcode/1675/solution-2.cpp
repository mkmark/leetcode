/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 531 ms, faster than 33.90% of C++ online submissions for Minimize Deviation in Array.
Memory Usage: 51.2 MB, less than 100.00% of C++ online submissions for Minimize Deviation in Array.
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
                nums[i] *= 2;
                nums_min = min(nums_min, nums[i]);
            }
            else {
                nums_min = min(nums_min, nums[i]);
            }
        }
        make_heap(begin(nums), end(nums));
        int min_diff = INT_MAX;
        int tmp;
        while (nums[0]%2 == 0){
            tmp = nums[0];
            min_diff = min(min_diff, nums[0] - nums_min);
            tmp/=2;
            nums_min = min(nums_min, tmp);
            pop_heap(begin(nums), end(nums));
            nums.back() = tmp;
            push_heap(begin(nums), end(nums));
        }
        return min(min_diff, nums[0] - nums_min);
    }
};
const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
