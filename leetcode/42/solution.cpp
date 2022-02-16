/*
author: mark@mkmark.net
time: O(n)
space: O(1)

Runtime: 11 ms, faster than 69.46% of C++ online submissions for Trapping Rain Water.
Memory Usage: 17.9 MB, less than 6.70% of C++ online submissions for Trapping Rain Water.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum_terrain = 0;
        int sum_envelope = 0;
        int ldx = 0;
        int rdx = n-1;
        int l_peek = 0;
        int r_peek = 0;
        while (ldx <= rdx){
            if (height[ldx] < height[rdx]){
                sum_terrain += height[ldx];
                l_peek = max(l_peek, height[ldx]);
                sum_envelope += l_peek;
                ++ldx;
            } else {
                sum_terrain += height[rdx];
                r_peek = max(r_peek, height[rdx]);
                sum_envelope += r_peek;
                --rdx;
            }
        }
        return sum_envelope - sum_terrain;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
