/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 1460 ms, faster than 5.04% of C++ online submissions for Minimum Height Trees.
Memory Usage: 461.7 MB, less than 5.03% of C++ online submissions for Minimum Height Trees.
*/

#include <vector>       // std::vector
#include <unordered_set>// std::unordered_set
#include <stack>        // std::stack
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    // middle of the graph
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // find dead ends
        vector<int> branch_count(n);
        vector<unordered_set<int>> branches(n);
        for (auto edge : edges){
            ++branch_count[edge[0]];
            ++branch_count[edge[1]];
            branches[edge[0]].insert(edge[1]);
            branches[edge[1]].insert(edge[0]);
        }

        int remaining_count = n;
        vector<int> is_deleted(n);
        while (remaining_count>2) {
            auto temp_branch_count = is_deleted;
            for (int i=0;i<n;++i){
                if (is_deleted[i]){
                    continue;
                }
                
                if (branch_count[i]==1){
                    is_deleted[i] = 1;
                    --remaining_count;
                    for (auto next_to_i : branches[i]){
                        branches[next_to_i].erase(i);
                        --temp_branch_count[next_to_i];
                    }
                }
            }
            branch_count = temp_branch_count;
        } 

        vector<int> result;
        for (int i=0;i<n;++i){
            if (!is_deleted[i]){
                result.push_back(i);
            }
        }

        return result;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);