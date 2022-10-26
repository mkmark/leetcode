/*
author: mark@mkmark.net
time: O(n+k)
space: O(k)

Runtime
415 ms
Beats
78.16%
Memory
130 MB
Beats
97.97%

deque with direct pop
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = size(nums);
        vi ans(n-k+1);
        for (int i=0; i<k; ++i){
            int num = nums[i];
            while(!q.empty() && num>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        for (int i=k; i<n; ++i){
            int l=i-k;
            ans[l] = nums[q.front()];
            int num = nums[i];
            while(!q.empty() && num>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if (q.front() <= l){
                q.pop_front();
            }
        }
        ans[n-k] = nums[q.front()];
        return ans;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
