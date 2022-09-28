/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 40 ms, faster than 100.00% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.
Memory Usage: 16.2 MB, less than 60.64% of C++ online submissions for Find the Longest Substring Containing Vowels in Even Counts.
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
        int pos_by_val[32];
        fill_n(pos_by_val, 32, -2);
        pos_by_val[0] = -1;
        int status = 0;
        int ans = 0;
        for (int i=0; i<n; ++i){
            switch (s[i]){
                case 'a':
                    status ^= 1;
                    break;
                case 'e':
                    status ^= 2;
                    break;
                case 'i':
                    status ^= 4;
                    break;
                case 'o':
                    status ^= 8;
                    break;
                case 'u':
                    status ^= 16; 
                    break;
            }
            if (pos_by_val[status] == -2){
                pos_by_val[status] = i;
            } else {
                ans = max(ans, i-pos_by_val[status]);
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
