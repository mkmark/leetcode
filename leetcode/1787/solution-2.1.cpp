/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 59 ms, faster than 99.05% of C++ online submissions for Make the XOR of All Segments Equal to Zero.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Make the XOR of All Segments Equal to Zero.

reference: sample 60 ms submission
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minChanges(vector<int> &nums, int k) {
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        int max_m = 1;

        int f[2][1024];

        // array of all possible candidate at i of k
        int a[2001];
        int size_a = 0;
        
        while(max_m < max_num) max_m<<=1;
        // max number to guess
        max_m = min(max_m+1, 1024);
        // 0x80808080 = 2155905152 = -2139062144
        memset(f[1], 0x80, sizeof f[0]);
        f[1][0] = 0;
        int mx = 0;
        int last, cnt, cur;
        for (int i = 0; i < k-1; ++i) {
            size_a = 0;
            for (int j = i; j < n; j += k)
                a[size_a++] = nums[j];
            sort(a, &a[size_a]);
            a[size_a++] = 1024;
            last = a[0];
            cnt = 0;
            cur = i & 1;
            mx = *max_element(f[cur ^ 1], f[cur ^ 1] + max_m);
            fill(f[cur], f[cur] + max_m, mx);
            for (int t=0; t<size_a; ++t) {
                if (last == a[t]) {
                    // cnt stores the count of last at position i+nk
                    ++cnt;
                    continue;
                }
                // j guess a number between 0 and max_m
                for (int j = 0; j < max_m; ++j){
                    // should we make the first i numbers has a xor sum of j, we can preserve f[cur][j] at most
                    f[cur][j] = max(f[cur][j], f[cur ^ 1][j ^ last] + cnt);
                }
                last = a[t];
                cnt = 1;
            }
        }
        size_a = 0;
        for (int j = k-1; j < n; j += k)
            a[size_a++] = nums[j];
        sort(a, &a[size_a]);
        a[size_a++] = 1024;
        last = a[0];
        cnt = 0;
        cur = k-1 & 1;
        mx = *max_element(f[cur ^ 1], f[cur ^ 1] + max_m);
        fill(f[cur], f[cur] + max_m, mx);
        for (int t=0; t<size_a; ++t) {
            if (last == a[t]) {
                // cnt stores the count of last at position i+nk
                ++cnt;
                continue;
            }
            f[cur][0] = max(f[cur][0], f[cur ^ 1][last] + cnt);
            last = a[t];
            cnt = 1;
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
