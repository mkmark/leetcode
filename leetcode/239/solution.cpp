/*
author: mark@mkmark.net
time: O(nlogk)
space: O()

Runtime
735 ms
Beats
26.89%
Memory
218.9 MB
Beats
6.50%

multiset
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> s;
        queue<multiset<int>::iterator> q;
        int n = size(nums);
        vi ans(n-k+1);
        for (int i = 0; i<k; ++i){
            q.push(s.emplace(nums[i]));
        }
        for (int i = 0; i<n-k; ++i){
            ans[i] = *s.begin();
            s.erase(q.front());
            q.pop();
            q.push(s.emplace(nums[i+k]));
        }
        ans[n-k] = *s.begin();
        return ans;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
