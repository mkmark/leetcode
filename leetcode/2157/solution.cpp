/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
*/

// wrong, cant solve { "a", "ac", "bd", "bcd", "abc" }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        bitset<26> words_b[20000];
        int grp[20000] = {};
        int grp_size[20001] = {};
        int n = words.size();

        sort(words.begin(), words.end(), [](string& i, string& j){return i.length() < j.length();});

        for (int i=0; i<n; ++i){
            words_b[i] = to_b(words[i]);
        }

        int grp_cnt = 1;

        for (int i=0; i<n; ++i){
            if (grp[i] == 0){
                grp[i] = grp_cnt++;
                ++grp_size[grp[i]];
            }

            for (int j=i+1; j<n; ++j){
                if (grp[j] > 0){
                    continue;
                }
                int diff_length = abs((int)(words_b[j].count() - words_b[i].count()));
                if (diff_length > 1){
                    break;
                }
                auto diff_cnt = (words_b[i] ^ words_b[j]).count();
                if (
                    diff_cnt <= 1 || 
                    (diff_cnt == 2 && diff_length == 0)
                ){
                    grp[j] = grp[i];
                    ++grp_size[grp[i]];
                }
            }
        }

        int max_grp_size = 0;
        for (int i=0; i<=grp_cnt; ++i){
            max_grp_size = max(max_grp_size, grp_size[i]);
        }

        vector<int> res = { --grp_cnt, max_grp_size };
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
