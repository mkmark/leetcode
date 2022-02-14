/*
author: mark@mkmark.net
time: O(NlogN)
space: O(N)

Runtime: 12 ms, faster than 100.00% of C++ online submissions for Minimum Number of Removals to Make Mountain Array.
Memory Usage: 12.6 MB, less than 9.55% of C++ online submissions for Minimum Number of Removals to Make Mountain Array.

reference: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/discuss/955088/C%2B%2B-O(n-log-n)
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <functional>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward = {nums[0]};
        vector<int> dp_forward(n);
        for (int i=1; i<=n-2; ++i){
            auto it = lower_bound(forward.begin(), forward.end(), nums[i]);
            if (it == forward.end()){
                forward.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            dp_forward[i] = forward.size();
        }
        vector<int> backward = {nums[n-1]};
        vector<int> dp_backward(n);
        for (int i=n-2; i>=1; --i){
            auto it = lower_bound(backward.begin(), backward.end(), nums[i]);
            if (it == backward.end()){
                backward.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            dp_backward[i] = backward.size();
        }

        int remain = 3;
        for (int i=1; i<n-1; ++i){
            if (dp_forward[i]<2 || dp_backward[i]<2){
                continue;
            }
            remain = max(
                remain,
                dp_forward[i] + dp_backward[i] - 1
            );
        }
        return n-remain;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
