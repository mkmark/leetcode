/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 266 ms, faster than 88.89% of C++ online submissions for Find the K-Sum of an Array.
Memory Usage: 74.5 MB, less than 44.44% of C++ online submissions for Find the K-Sum of an Array.

bfs + multiset
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        /// nlogn
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

        multiset<long long> s;

        vector<long long> subsets;
        subsets.push_back(smallest);
        s.insert(smallest);
        long long last_top = *s.begin();

        int count = 0;
        int pos = 0;

        int maximum = 0;

        /// k2
        while (count != k){
            if (s.empty() || (pos<n && *s.begin()>smallest+abs(nums[pos]))){
                int m = size(subsets);
                for (int i = 0; i<m; ++i){
                    long long new_num = subsets[i]+abs(nums[pos]);
                    if (size(s) < k-count){
                        subsets.push_back(new_num);
                        s.insert(new_num);
                    } else if (new_num < *prev(s.end())){
                        subsets.push_back(new_num);
                        s.erase(prev(s.end()));
                        s.insert(new_num);
                    }
                }
                ++pos;
            }
            last_top = *s.begin();
            s.erase(s.begin());
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
