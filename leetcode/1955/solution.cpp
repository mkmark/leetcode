/*
author: mark@mkmark.net
time: O(n)
space: O(1)

Runtime: 221 ms, faster than 100.00% of C++ online submissions for Count Number of Special Subsequences.
Memory Usage: 172.3 MB, less than 58.23% of C++ online submissions for Count Number of Special Subsequences.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    const int modulus = 1e9+7;
    int countSpecialSubsequences(vector<int>& nums) {
        int n = size(nums);
        /// cx = count of sub end with x
        int c0 = 2;
        int c1 = 0;
        int c2 = 0;
        
        for (int i = find(all(nums), 0) - begin(nums) + 1; i<n; ++i){
            if (nums[i] == 0) {
                c0 <<= 1;
                c0 %= modulus;
            } else if (nums[i] == 1) {
                c1 <<= 1;
                c1 %= modulus;
                c1 += c0-1;
                c1 %= modulus;
            } else {
                c2 <<= 1;
                c2 %= modulus;
                c2 += c1;
                c2 %= modulus;
            }
        }

        return c2;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
