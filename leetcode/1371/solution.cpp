/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 450 ms, faster than 6.64% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.
Memory Usage: 93.9 MB, less than 5.26% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = size(s);
        unordered_map<int, int> pos_by_val;
        int status = 0;
        int ans = 0;
        pos_by_val.emplace(0, -1);
        for (int i=0; i<n; ++i){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                status ^= (1<<(s[i]-'a'));
            }
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
