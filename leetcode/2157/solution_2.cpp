/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: TLE
Memory Usage: 
*/

// graph

#include <bits/stdc++.h>
#include "graph.cpp"
using namespace std;

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        bitset<26> words_b[20000];
        int n = words.size();

        sort(words.begin(), words.end(), [](string& i, string& j){return i.length() < j.length();});

        for (int i=0; i<n; ++i){
            words_b[i] = to_b(words[i]);
        }

        graph g(n);

        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                int diff_length = abs((int)(words_b[j].count() - words_b[i].count()));
                if (diff_length > 1){
                    break;
                }
                auto diff_cnt = (words_b[i] ^ words_b[j]).count();
                if (
                    diff_cnt <= 1 || 
                    (diff_cnt == 2 && diff_length == 0)
                ){
                    g.add_edge(i, j);
                }
            }
        }

        g.group();

        vector<int> res = { g.grp_cnt, g.max_grp_size() };
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

// const static auto initialize = [] {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return nullptr;
// }();
