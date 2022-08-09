/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 496 ms, faster than 99.44% of C++ online submissions for Minimum Interval to Include Each Query.
Memory Usage: 109.3 MB, less than 98.14% of C++ online submissions for Minimum Interval to Include Each Query.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& itvs, vector<int>& qris) {
        int n = size(qris);
        int m = size(itvs);

        int idx_qry[n];
        iota(idx_qry, idx_qry+n, 0);
        sort(idx_qry, idx_qry+n, [&qris](int & i, int & j){return qris[i] < qris[j];});

        sort(all(itvs));
        
        auto cmp = [](pair<int, int> &a, pair<int, int> &b){
            return a.second > b.second;
        };
        /// r, r-l+1
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        vi res(n);

        int idx;
        int num;
        int cur_idx_itv = 0;
        int l = itvs[0][0];
        int r = itvs[0][1];

        for (int i=0; i<n; ++i){
            idx = idx_qry[i];
            num = qris[idx];
            while(l <= num) {
                pq.push({r, r - l + 1});
                cur_idx_itv++;
                if (cur_idx_itv >= m) break;
                l = itvs[cur_idx_itv][0];
                r = itvs[cur_idx_itv][1];
            }
            /// not all are poped, but current top guarantees num in range
            while(!pq.empty() && pq.top().first < num){
                pq.pop();
            }

            if (pq.empty()){
                res[idx] = -1;
            } else {
                res[idx] = pq.top().second;
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
