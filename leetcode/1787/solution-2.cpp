/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 65 ms, faster than 100.00% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Make the XOR of All Segments Equal to Zero.

reference: sample 60 ms submission
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
int f[2][N];

class Solution {
public:
    int minChanges(vector<int> &nums, int k) {
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        int max_m = 1;
        while(max_m < max_num) max_m<<=1;
        max_m = min(max_m+1, N);
        vector<int> a;
        memset(f[1], 0x80, sizeof f[0]);
        f[1][0] = 0;
        for (int i = 0; i < k; ++i) {
            a.clear();
            for (int j = i; j < n; j += k)
                a.push_back(nums[j]);
            sort(a.begin(), a.end());
            a.push_back(N);
            int last = a[0], cnt = 0, cur = i & 1;
            int mx = *max_element(f[cur ^ 1], f[cur ^ 1] + N);
            fill(f[cur], f[cur] + N, mx);
            for (int x : a) {
                if (last == x) {
                    // cnt stores the count of x at position i+nk
                    ++cnt;
                    continue;
                }
                // j guess a number between 0 and N
                for (int j = 0; j < max_m; ++j)
                    f[cur][j] = max(f[cur][j], f[cur ^ 1][j ^ last] + cnt);
                last = x;
                cnt = 1;
            }
        }
        return n - f[(k - 1) & 1][0];
    }
};

const static auto initialize = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
