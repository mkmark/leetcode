/*
author: mark@mkmark.net
time: O(m+n)
space: O(n)

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Index of the First Occurrence in a String.
Memory Usage: 6.2 MB, less than 60.31% of C++ online submissions for Find the Index of the First Occurrence in a String.
kmp
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int strStr(string text, string pattern) {
        int m = size(text);
        int n = size(pattern);
        /// fallback array
        int fb[n];
        fb[0] = 0;
        for (int i=1, j=0; i<n;){
            if (pattern[i] == pattern[j]){
                ++j;
                fb[i] = j;
                ++i;
            } else {
                if (j>0){
                    j = fb[j-1];
                } else {
                    fb[i] = 0;
                    ++i;
                }
            }
        }

        for (int i=0, j=0; i<=m;){
            if (text[i] == pattern[j]){
                ++i;
                ++j;
                if (j==n){
                    return i-j;
                }
            } else {
                if (j>0){
                    j = fb[j-1];
                } else {
                    ++i;
                }
            }
        }

        return -1;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
