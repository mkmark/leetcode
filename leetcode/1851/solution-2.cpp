/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 748 ms, faster than 79.22% of C++ online submissions for Minimum Interval to Include Each Query.
Memory Usage: 144.6 MB, less than 20.04% of C++ online submissions for Minimum Interval to Include Each Query.
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

        auto cmp = [](pair<int, int> a, pair<int, int> b) { 
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first; 
        };
        /// sorted by r-l+1, distinguished by additional nonduplicate index
        set<pair<int, int>, decltype(cmp)> s(cmp);
        /// track the iterator of element in s with least r
        /// sorted by r, distinguished by additional nonduplicate index
        map<pair<int, int>, set<pair<int, int>, decltype(cmp)>::iterator, decltype(cmp)> it_s(cmp);

        vi res(n);
        
        int idx;
        int num;
        int cur_idx_itv = 0;
        vi * cur_itv = &itvs[cur_idx_itv];
        int l = (*cur_itv)[0];
        int r = (*cur_itv)[1];
        for (int i=0; i<n; ++i){
            idx = idx_qry[i];
            num = qris[idx];
            while (!it_s.empty() && (*it_s.begin()).first.first < num){
                s.erase((*it_s.begin()).second);
                it_s.erase(it_s.begin());
            }
            while (l <= num){
                if (r >= num){
                    it_s.insert({{r, cur_idx_itv}, s.insert({r - l + 1, cur_idx_itv}).first});
                }
                ++cur_idx_itv;
                if (cur_idx_itv >= m) break;
                cur_itv = &itvs[cur_idx_itv];
                l = (*cur_itv)[0];
                r = (*cur_itv)[1];
            }
            if (s.empty()){
                res[idx] = -1;
            } else {
                res[idx] = (*s.begin()).first;
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
