/*
author: mark@mkmark.net
time: O(n)
space: O(1)

Runtime: 52 ms, faster than 98.79% of C++ online submissions for Minimum Time to Remove All Cars Containing Illegal Goods.
Memory Usage: 30.4 MB, less than 86.61% of C++ online submissions for Minimum Time to Remove All Cars Containing Illegal Goods.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        // sweep right, has a constant -1 pressure, but +2 when meet '1', -1+2=+1
        int fwd = 0;
        // fwd_max is the point where +2 accumulates its max advantage, thus should consider switching to op 2
        int fwd_max = 0;
        // max_diff record the max difference it can drop after a fwd_max, which is the saved time if switching at correspongding fwd_max
        int max_diff = 0;
        for (int i=0; i<n; ++i){
            if (s[i]=='1'){
                fwd_max = max(fwd_max, ++fwd);
            } else {
                max_diff = max(max_diff, fwd_max-(--fwd));
            }
        }
        // res = full time - saved time
        return n - max_diff;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
