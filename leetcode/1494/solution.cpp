/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 149 ms, faster than 50.41% of C++ online submissions for Parallel Courses II.
Memory Usage: 37.1 MB, less than 17.48% of C++ online submissions for Parallel Courses II.

bfs
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

typedef int bint;

class Solution {
public:
    bint rel[16] = {};
    int required[16] = {};
    int fulfilled[16];
    int k;
    int n;
    int minNumberOfSemesters(int course_count, vector<vector<int>>& relations, int max_to_take) {
        k = max_to_take;
        n = course_count;
        /// n=2, toTakeNextTerm = 0x...110
        // can_take_first_term = (1<<(n+1)) - 2;
        for (auto & relation : relations){
            rel[relation[1]] |= 1<<relation[0];
            ++required[relation[1]];
            // can_take_first_term &= ~1<<relation[1];
        }

        vi takens = {0};
        bfs(takens);

        return term_count;
    }

    int term_count = 0;
    int seen[65536] = {};
    void bfs(vi & takens){
        vi to_takes;
        for (auto & taken : takens){
            /// get course can be taken this term according to taken
            auto can_take_this_term = get_can_take_this_term(taken);
            if (can_take_this_term == 0){
                return;
            }
            /// select k courses from can_take_this_term
            auto selects_this_term = get_selects_this_term(can_take_this_term);
            for (auto & new_taken : selects_this_term){
                int to_take = taken | new_taken;
                if (!seen[to_take]){
                    seen[to_take] = 1;
                    to_takes.push_back(to_take);
                }
            }
        }
        ++term_count;
        bfs(to_takes);
    }

    /// O(n2)
    inline int get_can_take_this_term(int & taken){
        memset(fulfilled+1, 0, 4*n);
        bint can_take_this_term = 0;
        /// O(n2)
        for (int j = 1; j<=n; ++j){
            // bint fulfilled_j = rel[j] & taken;
            // while (fulfilled_j!=0){
            //     if (fulfilled_j & 1) ++fulfilled[j];
            //     fulfilled_j >>= 1;
            // }
            fulfilled[j] = __builtin_popcount(rel[j] & taken);
        }
        for (int i=1; i<=n; ++i){
            if (fulfilled[i] >= required[i]){
                can_take_this_term |= 1<<i;
            }
        }
        can_take_this_term &= ~taken;
        return can_take_this_term;
    }

    inline vi get_selects_this_term(int & can_take_this_term){
        // int cnt_can_take_this_term = 0;
        // int tmp = can_take_this_term;
        // while (tmp!=0){
        //     if (tmp & 1) ++cnt_can_take_this_term;
        //     tmp >>= 1;
        // }
        // if (cnt_can_take_this_term<=k) return {can_take_this_term};
        if (__builtin_popcount(can_take_this_term)<=k) return {can_take_this_term};

        vi pos_1;
        pos_1.reserve(n);
        for (int i=0; can_take_this_term!=0; ++i){
            if (can_take_this_term & 1) pos_1.push_back(i);
            can_take_this_term >>= 1;
        }
        int N = pos_1.size();

        string bitmask(k, 1);
        bitmask.resize(N, 0);

        vi res;
        do {
            int select = 0;
            for (int i = 0; i < N; ++i) // [0..N-1] integers
            {
                if (bitmask[i]) {
                    select |= 1<<pos_1[i];
                }
            }
            res.push_back(select);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

        return res;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
