/*
author: mark@mkmark.net
time: O(nlogn)
space: O(1)

Runtime: 278 ms, faster than 63.53% of C++ online submissions for Maximum Gap.
Memory Usage: 81.9 MB, less than 43.12% of C++ online submissions for Maximum Gap.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(all(nums));
        int res = 0;
        int n = size(nums);
        for (int i=1;i<n;++i){
            res = max(res, nums[i]-nums[i-1]);
        }
        return res;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
