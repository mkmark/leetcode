/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 1612 ms, faster than 34.90% of C++ online submissions for Groups of Strings.
Memory Usage: 71.3 MB, less than 64.43% of C++ online submissions for Groups of Strings.
*/

// union find

#include <bits/stdc++.h>
#include "disjoint_set.hpp"
using namespace std;

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        vector<bitset<26>> words_b;
        map<int, int> words_b_count;

        int n = words.size();

        for (int i=0; i<n; ++i){
            auto word_b = to_b(words[i]);
            auto mask = (int)word_b.to_ullong();
            if (words_b_count[mask]){
                ++words_b_count[mask];
            } else {
                words_b.push_back(word_b);
                words_b_count[mask] = 1;
            }
        }

        sort(words_b.begin(), words_b.end(), [](bitset<26>& i, bitset<26>& j){return i.count() < j.count();});

        int m = words_b.size();

        if (m == 1){
            vector<int> res = { 1, words_b_count[(int)words_b[0].to_ullong()] };
            return res;
        }

        vector<int> val(m);
        for (int i=0; i<m; ++i){
            val[i] = words_b_count[(int)words_b[i].to_ullong()];
        }

        disjoint_set ds(m, val);


        for (int i=0; i<m; ++i){
            for (int j=i+1; j<m; ++j){
                int diff_length = abs((int)(words_b[j].count() - words_b[i].count()));
                // rely on sorted vec
                if (diff_length > 1){
                    break;
                }
                auto diff_cnt = (words_b[i] ^ words_b[j]).count();
                if (
                    diff_cnt <= 1 || 
                    (diff_cnt == 2 && diff_length == 0)
                ){
                    ds.union_set(i, j);
                }
            }
        }

        vector<int> res = { ds.set_cnt, ds.max_sum_val };

        return res;
    }

    inline bitset<26> to_b(string word){
        bitset<26> b;
        for (auto c : word) {
            b |= (1<<(c-'a'));
        }
        return b;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
