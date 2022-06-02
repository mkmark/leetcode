/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 7 ms, faster than 93.13% of C++ online submissions for Edit Distance.
Memory Usage: 9.1 MB, less than 37.79% of C++ online submissions for Edit Distance.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    string w1;
    string w2;
    vvi dp;
    int minDistance(string word1, string word2) {
        w1 = word1;
        w2 = word2;
        int l1 = size(w1);
        int l2 = size(w2);
        dp.resize(l1+1, vi(l2+1));
        int res = find_min_dist(l1, l2);
        return res;
    }

    int find_min_dist(int i, int j){
        if (i==0 || j==0) return max(i, j);
        if (dp[i][j]) return dp[i][j];
        if (w1[i-1] == w2[j-1]) {
            return dp[i-1][j-1]=find_min_dist(i-1, j-1);
        } else {
            return dp[i][j]=min3(
                find_min_dist(i-1, j-1) + 1,
                find_min_dist(i, j-1) + 1,
                find_min_dist(i-1, j) + 1
            );
        };
    }

    inline int min3(int a, int b, int c){
        return min(min(a, b), c);
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
