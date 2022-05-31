/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 8 ms, faster than 99.35% of C++ online submissions for Number of Ways to Rearrange Sticks With K Sticks Visible.
Memory Usage: 10 MB, less than 90.20% of C++ online submissions for Number of Ways to Rearrange Sticks With K Sticks Visible.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int dp[1001][1001] = {};
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        if (dp[n][k]) return dp[n][k];
        if (n==k) return dp[n][k] = 1;
        if (k==0) return 0;
        return dp[n][k] = (rearrangeSticks(n-1, k-1) + (long long)(n-1)*rearrangeSticks(n-1, k)) % (1000000007);
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
