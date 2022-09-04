/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 

reference: leetcode 246ms solution

pq
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    long long kthLargestSum(vector<int>& nums, int k) {
        long long m = 0; 
        vector<int> vals; 
        for (auto& x : nums) {
            if (x > 0) m += (long long) x; 
            vals.push_back(abs(x)); 
        }
        sort(vals.begin(), vals.end()); 
        
        long long ans = 0; 
        priority_queue<pair<long long, int>> pq; pq.emplace(m, 0); 
        for (; k; --k) {
            auto [x, i] = pq.top(); pq.pop(); 
            ans = x; 
            if (i < nums.size()) {
                pq.emplace(x - vals[i], i+1); 
                if (i) pq.emplace(x + vals[i-1] - vals[i], i+1); 
            }
        }
        return ans; 
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
