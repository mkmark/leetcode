/*
author: mark@mkmark.net
time: O()
space: O()

count from start of the path
remove the dead starts as couting as a recursive approach
*/

#include <vector>       // std::vector
#include <string>       // std::string
#include <queue>        // std::queue
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    int largestPathValue(std::string colors, std::vector<std::vector<int>>& edges) {
        int n = colors.length();
        
        vector<vector<int>> nodes_from(n, vector<int>());
        vector<int> in_count(n, 0);

        for(vector<int>& edge : edges) {
            int node_from = edge[0];
            int node_to = edge[1];
            in_count[node_to]++;
            nodes_from[node_from].push_back(node_to);
        }

        // processing queue with all the dead starts
        queue<int> q;
        vector<int[26]> color_count_by_node_by_color(n);

        for(int i=0;i<n;++i) {
            if (in_count[i] == 0){
                q.push(i);
            }
        }

        int max_count = -1;
        vector<int> is_processed(n, 0);

        for(int i=0;i<n;++i) {
            if(q.empty()) break;
            int some_start = q.front();
            is_processed[some_start] = 1;
            q.pop();

            ++ color_count_by_node_by_color[some_start][colors.at(some_start)-'a'];
            if (nodes_from[some_start].size() == 0){
                for (auto count : color_count_by_node_by_color[some_start]){
                    max_count = max(max_count, count);
                }
            } else {
                for (auto node_from_some_start : nodes_from[some_start]){
                    for (auto j=0;j<26;++j){
                        color_count_by_node_by_color[node_from_some_start][j] = max(
                            color_count_by_node_by_color[node_from_some_start][j],
                            color_count_by_node_by_color[some_start][j]
                        );
                    }
                    if (--in_count[node_from_some_start] == 0){
                        q.push(node_from_some_start);
                    }
                }
            }
        }

        for(int i=0;i<n;++i) {
            if (is_processed[i] == 0){
                return -1;
            }
        }

        return max_count;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);