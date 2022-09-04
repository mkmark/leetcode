/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 357 ms, faster than 66.67% of C++ online submissions for Find the K-Sum of an Array.
Memory Usage: 82.6 MB, less than 44.44% of C++ online submissions for Find the K-Sum of an Array.

bfs + multiset + multiset
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

        multiset<long long> subsets;
        subsets.insert(smallest);
        s.insert(smallest);
        long long last_top = *s.begin();

        int count = 0;
        int pos = 0;

        int maximum = 0;

        /// k2
        while (count != k){
            if (s.empty() || (pos<n && *s.begin()>smallest+abs(nums[pos]))){
                multiset<long long> to_insert;
                for (auto i : subsets){
                    long long new_num = i+abs(nums[pos]);
                    if (size(s) < k-count){
                        to_insert.insert(new_num);
                        s.insert(new_num);
                    } else if (new_num < *prev(s.end())){
                        to_insert.insert(new_num);
                        s.erase(prev(s.end()));
                        s.insert(new_num);
                    } else {
                        break;
                    }
                }
                subsets.merge(to_insert);
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
