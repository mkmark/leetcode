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
    int solution(vi jobs, vi a, vi b, int k) {
        uint16_t n = size(jobs);
        /// score_by_pos[pos] = score
        unordered_map<uint16_t, int> score_by_pos;
        score_by_pos.emplace(k, 0);

        int max_new_score = 0;
        int second_max_new_score = 0;
        int last_pos = k;
        bool last_lazy;
        for (int day=0; day<n; ++day){ 
            
            if (jobs[day] == last_pos){
                max_new_score = second_max_new_score + b[day];
            } else {
                second_max_new_score = max_new_score;
                max_new_score += b[day];
            }

            auto it = score_by_pos.find(jobs[day]);
            if (it != score_by_pos.end()){
                int lazy_new_score = (*it).second + a[day];
                max_new_score = max(max_new_score, lazy_new_score);
            }

            last_pos = jobs[day];
            score_by_pos[jobs[day]] = max_new_score;
        }

        return max_new_score;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
