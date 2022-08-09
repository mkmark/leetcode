/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
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

        /// sorted by r-l+1, distinguished by additional nonduplicate index
        set<long long> s;
        /// track the iterator of element in s with least r
        /// sorted by r, distinguished by additional nonduplicate index
        map<long long, set<long long>::iterator> it_s;

        vi res(n);
        
        int idx;
        int num;
        int cur_idx_itv = 0;
        vi * cur_itv = &itvs[cur_idx_itv];
        int l = (*cur_itv)[0];
        long long r = (*cur_itv)[1];
        for (int i=0; i<n; ++i){
            idx = idx_qry[i];
            num = qris[idx];
            while (!it_s.empty() && ((*it_s.begin()).first>>32) < num){
                s.erase((*it_s.begin()).second);
                it_s.erase(it_s.begin());
            }
            while (l <= num){
                if (r >= num){
                    it_s.insert({(r<<32) + cur_idx_itv, s.insert(((r - l + 1)<<32) + cur_idx_itv).first});
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
                res[idx] = (*s.begin())>>32;
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
