/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime: 169 ms, faster than 98.21% of C++ online submissions for Maximum Gap.
Memory Usage: 82.9 MB, less than 33.28% of C++ online submissions for Maximum Gap.

reference: https://leetcode.com/problems/maximum-gap/discuss/50694/12ms-C%2B%2B-Suggested-Solution
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = size(nums);
        if (n < 2) return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u = *lu.second;
        int gap = max((u - l) / (n - 1), 1);
        int m = (u - l) / gap + 1;
        // vector<int> bucketsMin(m, INT_MAX);
        // vector<int> bucketsMax(m, INT_MIN);
        int bucketsMin[m];
        fill_n(bucketsMin, m, INT_MAX);
        int bucketsMax[m];
        fill_n(bucketsMax, m, INT_MIN);
        int k;
        for (int & num : nums) {
            k = (num - l) / gap;
            if (num < bucketsMin[k]) bucketsMin[k] = num;
            if (num > bucketsMax[k]) bucketsMax[k] = num;
        }
        int i = 0, j; 
        gap = bucketsMax[0] - bucketsMin[0];
        while (i < m) {
            j = i + 1;
            while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
                j++;
            if (j == m) break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
