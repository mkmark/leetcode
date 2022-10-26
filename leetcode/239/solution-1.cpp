/*
author: mark@mkmark.net
time: O(nlogk)
space: O(n+k)

Runtime
1167 ms
Beats
8.54%
Memory
132.2 MB
Beats
97.6%

deque with upper_bound
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        int n = size(nums);
        vi ans(n-k+1);
        for (int i=0; i<k; ++i){
            auto it = upper_bound(q.begin(), q.end(), make_pair(nums[i],i), [](const pair<int, int>& i, const pair<int, int>& j){return i.first>j.first;});
            int new_end = it-q.begin();
            q.resize(new_end+1);
            q[new_end] = make_pair(nums[i],i);
        }
        for (int i=0; i<n-k; ++i){
            ans[i] = q.front().first;
            auto it = upper_bound(q.begin(), q.end(), make_pair(nums[i+k],i+k), [](const pair<int, int>& i, const pair<int, int>& j){return i.first>j.first;});
            int new_end = it-q.begin();
            q.resize(new_end+1);
            q[new_end] = make_pair(nums[i+k],i+k);
            if ((*q.begin()).second<=i){
                q.pop_front();

            }
        }
        ans[n-k] = q.front().first;
        return ans;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
