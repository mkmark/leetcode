/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 218 ms, faster than 93.81% of C++ online submissions for Shortest Impossible Sequence of Rolls.
Memory Usage: 113.7 MB, less than 54.58% of C++ online submissions for Shortest Impossible Sequence of Rolls.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        /// position sequence of any given number
        vector<vi> pos_seqs(k+1);
        int pos = 0;
        for (auto & roll : rolls){
            pos_seqs[roll].push_back(pos++);
        }

        /// position of any given number now
        vector<vi::iterator> pos_now_its(k+1);
        int res = 1;
        int pos_next_min = 0;
        for (int i=1; i<=k; ++i){
            if (pos_seqs[i].size() == 0){
                return res;
            }
            pos_now_its[i] = pos_seqs[i].begin();
            pos_next_min = max(pos_next_min, pos_seqs[i][0]+1);
        }

        int pos_now_min;
        vi::iterator it;
        for (res = 2;; ++res){
            pos_now_min = pos_next_min;
            for (int i=1; i<=k; ++i){
                it = lower_bound(pos_now_its[i], pos_seqs[i].end(), pos_now_min);
                if (it == pos_seqs[i].end()){
                    return res;
                } else {
                    pos_now_its[i] = it;
                    pos_next_min = max(pos_next_min, *it+1);
                }
            }
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
