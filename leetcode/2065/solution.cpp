/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 93 ms, faster than 100.00% of C++ online submissions for Maximum Path Quality of a Graph.
Memory Usage: 28.5 MB, less than 7.23% of C++ online submissions for Maximum Path Quality of a Graph.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution
{
public:
    int max_time;
    int max_sum = 0;
    // dp[pos, sum] = time
    unordered_map<long long, int> dp;
    // neighbours[pos][target_index] = {target_pos, time_of_edge}
    vector<vector<pair<int, int>>> neighbours;
    // visited[index] = pos
    int visited[12];

    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        max_time = maxTime;
        int n = size(values);
        neighbours.resize(n);
        for (auto edge : edges)
        {
            neighbours[edge[0]].push_back(make_pair(edge[1], edge[2]));
            neighbours[edge[1]].push_back(make_pair(edge[0], edge[2]));
        }

        visited[0] = 0;
        int visited_size = 1;
        
        dfs_max_path_quality(
            0,
            0,
            values[0],
            values,
            visited_size
        );
        return max_sum;
    }

    void dfs_max_path_quality(
        int time,
        int pos,
        int sum,
        vector<int>& values,
        int visited_size
    )
    {
        if (pos == 0)
        {
            max_sum = max(max_sum, sum);
        }
        for (auto neighbour : neighbours[pos])
        {
            if (time + neighbour.second > max_time){
                continue;
            }
            // if neighbour is visited before
            if (find(visited, visited+visited_size, neighbour.first) != visited+visited_size){
                auto it = dp.find(((long long)neighbour.first<<32)+sum);
                // if neighbour is reached previously with exact same sum, trim this senario
                if (it != dp.end() && it->second <= time + neighbour.second){
                    continue;
                }
                // record pos, sum, and time
                dp[((long long)neighbour.first<<32)+sum] = time + neighbour.second;
                dfs_max_path_quality(
                    time + neighbour.second,
                    neighbour.first,
                    sum,
                    values,
                    visited_size
                );
            // if neighbour is first time visited
            } else {
                // record pos, sum, and time
                dp[((long long)neighbour.first<<32)+sum+values[neighbour.first]] = time + neighbour.second;
                // mark visited
                visited[visited_size] = neighbour.first;
                dfs_max_path_quality(
                    time + neighbour.second,
                    neighbour.first,
                    sum + values[neighbour.first],
                    values,
                    visited_size+1
                );
            }
        }
    }
};

const static auto initialize = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
