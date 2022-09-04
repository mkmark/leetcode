/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: tle
Memory Usage: 

bfs + pq
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        sort(all(nums), [&nums](int & i, int & j){return abs(i)<abs(j);});
        long long sum = 0;
        long long smallest = 0;

        int n = size(nums);
        for (int i=0; i<n; ++i){
            sum += nums[i];
            if (nums[i]<0) {
                smallest += nums[i];
            }
        }

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        vector<long long> subsets;
        subsets.push_back(smallest);
        pq.push(smallest);
        long long last_top = pq.top();

        int count = 0;
        int pos = 0;

        int maximum = 0;

        while (count != k){
            if (pq.empty() || (pos<n && pq.top()>smallest+abs(nums[pos]))){
                int m = size(subsets);
                subsets.resize(m<<1);
                for (int i = 0; i<m; ++i){
                    long long new_num = subsets[i]+abs(nums[pos]);
                    subsets[m+i]=new_num;
                    pq.push(new_num);
                }
                ++pos;
            }
            last_top = pq.top();
            pq.pop();
            ++count;
        }
        return sum-last_top;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
