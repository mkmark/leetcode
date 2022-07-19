/*
author: mark@mkmark.net
time: O(mlogm)
space: O(m)

Runtime: 459 ms, faster than 100.00% of C++ online submissions for Maximum Building Height.
Memory Usage: 100.3 MB, less than 100.00% of C++ online submissions for Maximum Building Height.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rs) {
        /// O(mlogm)
        sort(all(rs), [&rs](vi& i, vi& j){return i[0]<j[0];});

        /// solve for y=x+b1, y=-x+b2
        /// result is x=(b2-b1)/2, y = x+b1

        int b1s[100000];
        int bs_last = 0;
        int b2s[100000];

        b1s[0] = -1;
        b2s[0] = 0;

        int b1 = -1;
        int b2;
        for (int i=0; i<size(rs); ++i){
            b1 = rs[i][1]-rs[i][0];
            if (b1 < b1s[bs_last]){
                b2 = rs[i][0]+rs[i][1];
                if (b2 > b2s[bs_last]){
                    b1s[++bs_last] = b1;
                    b2s[bs_last] = b2;
                } else {
                    bs_last = lower_bound(b2s, b2s+bs_last+1, b2) - b2s;
                    b1s[bs_last] = b1;
                    b2s[bs_last] = b2;
                }
            }
        }

        int y_max = n + min(b1, b1s[bs_last]);
        for (int i=1; i<=bs_last; ++i){
            y_max = max(y_max, (b1s[i-1]+b2s[i])/2);
        }

        return y_max;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
