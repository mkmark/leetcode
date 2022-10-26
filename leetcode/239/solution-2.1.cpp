/*
author: mark@mkmark.net
time: O(n+k)
space: O(n+k)

Runtime
191 ms
Beats
100%
Memory
128.3 MB
Beats
99.87%

deque with direct pop, rewritten with []
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = size(nums);
        int q[n+k];
        int front = 0;
        int back = 0;
        vi ans(n-k+1);
        for (int i=0; i<k; ++i){
            int num = nums[i];
            while(back-front>0 && num>nums[q[back-1]]){
                --back;
            }
            q[back++] = i;
        }
        for (int i=k; i<n; ++i){
            int l = i-k;
            ans[l] = nums[q[front]];
            int num = nums[i];
            while(back-front>0 && num>nums[q[back-1]]){
                --back;
            }
            q[back++] = i;
            if (q[front] <= l){
                ++front;
            }
        }
        ans[n-k] = nums[q[front]];
        return ans;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
