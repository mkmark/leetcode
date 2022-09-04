/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int solution(string s) {
        int n = size(s);
        unordered_map<uint32_t, int> pos_by_val;
        uint32_t status = 0;
        int ans = 0;
        for (int i=0; i<n; ++i){
            status ^= s[i]-'a';
            auto res = pos_by_val.emplace(status, i);
            if (!res.second){
                ans = max(ans, i-(*res.first).second);
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
