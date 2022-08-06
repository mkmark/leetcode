/*
author: mark@mkmark.net
time: O(n)
space: O(k)

Runtime: 83 ms, faster than 100.00% of C++ online submissions for Shortest Impossible Sequence of Rolls.
Memory Usage: 86.9 MB, less than 95.12% of C++ online submissions for Shortest Impossible Sequence of Rolls.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int seen[k+1];
        int memset_bytes = 4*k+4;
        memset(seen, 0, memset_bytes);
        int cnt = 0;
        int res = 1;
        for (auto & roll : rolls){
            if (!seen[roll]){
                seen[roll] = 1;
                ++cnt;
                if (cnt == k){
                    memset(seen, 0, memset_bytes);
                    ++res;
                    cnt = 0;
                }
            }
        }
        return res;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
