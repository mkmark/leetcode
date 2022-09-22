/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime: 153 ms, faster than 99.36% of C++ online submissions for Largest Rectangle in Histogram.
Memory Usage: 76.5 MB, less than 77.82% of C++ online submissions for Largest Rectangle in Histogram.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<pair<int,int>> ms;
        int n = size(heights);
        // int ls[n];
        int rs[n];

        for (int i=n-1; i>=0; --i){
            int height = heights[i];
            while (!ms.empty() && ms.top().first>=height){
                ms.pop();
            }
            rs[i] = ms.empty() ? n : ms.top().second;
            ms.emplace(height,i);
        }

        ms = {};

        for (int i=0; i<n; ++i){
            int height = heights[i];
            while (!ms.empty() && ms.top().first>=height){
                ms.pop();
            }
            // ls[i] = ms.empty() ? -1 : ms.top().second;
            int l = ms.empty() ? -1 : ms.top().second;
            ans = max(ans, height*(rs[i]-l-1));
            ms.emplace(height,i);
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
