/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 

bfs + multimap + multiset
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

        multiset<long long> subsets;
        multimap<long long, multiset<long long>::iterator> s;
        s.insert({smallest, subsets.insert(smallest)});
        long long last_top = (*s.begin()).first;

        int count = 0;
        int pos = 0;

        int maximum = 0;

        /// k2
        while (count != k){
            if (s.empty() || (pos<n && (*s.begin()).first>smallest+abs(nums[pos]))){
                multiset<long long> to_insert;
                vector<multiset<long long>::iterator> to_erase;
                for (auto i : subsets){
                    long long new_num = i+abs(nums[pos]);
                    if (size(s) < k-count){
                        s.insert({new_num, to_insert.insert(new_num)});
                    } else if (new_num < (*prev(s.end())).first){
                        to_erase.push_back((*prev(s.end())).second);
                        s.erase(prev(s.end()));
                        s.insert({new_num, to_insert.insert(new_num)});
                    } else {
                        break;
                    }
                }
                subsets.merge(to_insert);
                for (auto it : to_erase){
                    subsets.erase(it);
                }
                ++pos;
            }
            last_top = (*s.begin()).first;
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
