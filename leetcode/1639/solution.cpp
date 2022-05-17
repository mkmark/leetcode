/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 182 ms, faster than 100.00% of C++ online submissions for Number of Ways to Form a Target String Given a Dictionary.
Memory Usage: 37.8 MB, less than 63.33% of C++ online submissions for Number of Ways to Form a Target String Given a Dictionary.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dp_choice[target_pos][word_pos]
    int dp_choice[1000][1000];
    // count[word_pos][alphabet]
    int count[1000][26] = {};
    int word_length;
    int target_length;
    string target;

    int numWays(vector<string>& words, string t) {
        memset(dp_choice, -1, sizeof dp_choice);
        target = t;
        word_length = size(words[0]);
        target_length = size(target);

        for (auto word : words){
            for (int i = 0; i<word_length; ++i){
                count[i][word[i]-'a']++;
            }
        }

        return dfs(0, 0);
    }

    int dfs(int target_pos, int word_pos){
        if (target_pos == target_length - 1){
            if (word_pos < word_length && dp_choice[target_pos][word_pos] >= 0){
                return dp_choice[target_pos][word_pos];
            }
            int remain = 0;
            int word_pos_temp = word_pos;
            if (word_pos < word_length){
                while (word_pos_temp < word_length){
                    remain += count[word_pos_temp++][target[target_pos]-'a'];
                }
                return dp_choice[target_pos][word_pos] = remain;
            } else {
                return 0;
            }
        }
        if (word_pos == word_length){
            return 0;
        }
        if (dp_choice[target_pos][word_pos] >= 0){
            return dp_choice[target_pos][word_pos];
        }

        return dp_choice[target_pos][word_pos] = int(
            (
                dfs(target_pos, word_pos+1) + 
                count[word_pos][target[target_pos]-'a'] * long(dfs(target_pos+1, word_pos+1))
            ) % (1000000007)
        );
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
