/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 466 ms, faster than 99.78% of C++ online submissions for Grid Illumination.
Memory Usage: 101.9 MB, less than 91.70% of C++ online submissions for Grid Illumination.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    /// x == xi
    /// y == yi
    /// y-x == yi-xi
    /// y+x == yi+xi

    // struct v_hash
    // {
    //     long long operator() (const vi & v) const {
    //         return v[0] << 32 + v[1];
    //     }
    // };

    template <class K, class V>
    inline void inc_map(unordered_map<K, V> & mp, K k){
        auto it = mp.find(k);
        if (it==mp.end()) {
            mp.insert({k,1});
        } else {
            ++(*it).second;
        }
    }

    template <class K, class V>
    inline void dec_map(unordered_map<K, V> & mp, K k){
        auto it = mp.find(k);
        if ((--(*it).second) == 0) {
            mp.erase(it);
        }
    }

    template <class K, class V>
    inline int pos_cnt(unordered_map<K, V> & mp, K k){
        return mp.find(k) != mp.end();
    }

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries){
        // unordered_set<vector<int>, v_hash> lmps;
        unordered_set<long long> lmps;
        unordered_map<int, int> lmps_x_count;
        unordered_map<int, int> lmps_y_count;
        unordered_map<int, int> lmps_ymx_count;
        unordered_map<int, int> lmps_ypx_count;

        for (auto lamp : lamps){
            if (lmps.insert(((long long)lamp[0]<<32) + lamp[1]).second) {
                inc_map(lmps_x_count, lamp[0]);
                inc_map(lmps_y_count, lamp[1]);
                inc_map(lmps_ymx_count, lamp[1]-lamp[0]);
                inc_map(lmps_ypx_count, lamp[1]+lamp[0]);
            }
        }

        int m = size(queries);
        vector<int> res(m);

        int a, b, xi, yi;
        std::unordered_set<long long>::iterator it;
        for (int i = 0; i < m; ++i){
            xi = queries[i][0];
            yi = queries[i][1];
            res[i] = pos_cnt(lmps_x_count, xi) ||
                pos_cnt(lmps_y_count, yi) ||
                pos_cnt(lmps_ymx_count, yi-xi) ||
                pos_cnt(lmps_ypx_count, yi+xi);

            for (a = max(xi-1, 0); a < min(xi+2, n); ++a){
                for (b = max(yi-1, 0); b < min(yi+2, n); ++b){
                    it = lmps.find(((long long)a<<32) + b);
                    if (it != lmps.end()){
                        lmps.erase(it);
                        dec_map(lmps_x_count, a);
                        dec_map(lmps_y_count, b);
                        dec_map(lmps_ymx_count, b-a);
                        dec_map(lmps_ypx_count, b+a);
                    }
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
