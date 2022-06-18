/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 139 ms, faster than 97.93% of C++ online submissions for Maximum Path Quality of a Graph.
Memory Usage: 34.5 MB, less than 6.80% of C++ online submissions for Maximum Path Quality of a Graph.
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
    // dp[pos][sum] = time
    unordered_map<long long, int> dp;
    // neighbours[pos][target_index] = {target_pos, time_of_edge}
    vector<vector<pair<int, int>>> neighbours;

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

        int visited[1] = {};
        int visited_size = 1;
        
        dfs_max_path_quality(
            0,
            0,
            values[0],
            values,
            visited,
            visited_size
        );
        return max_sum;
    }

    void dfs_max_path_quality(
        int time,
        int pos,
        int sum,
        vector<int>& values,
        int *visited,
        int visited_size
    )
    {
        if (time <= max_time)
        {
            if (pos == 0)
            {
                max_sum = max(max_sum, sum);
            }
            for (auto neighbour : neighbours[pos])
            {
                if (find(visited, visited+visited_size, neighbour.first) != visited+visited_size)
                {
                    auto it = dp.find(((long long)neighbour.first<<32)+sum);
                    if (it != dp.end() && it->second <= time + neighbour.second){
                        continue;
                    }
                    dp[((long long)neighbour.first<<32)+sum] = time + neighbour.second;
                    dfs_max_path_quality(
                        time + neighbour.second,
                        neighbour.first,
                        sum,
                        values,
                        visited,
                        visited_size
                    );
                }
                else
                {
                    dp[((long long)neighbour.first<<32)+sum+values[neighbour.first]] = time + neighbour.second;
                    int new_visited[12];
                    copy(visited, visited+visited_size, new_visited);
                    new_visited[visited_size] = neighbour.first;
                    dfs_max_path_quality(
                        time + neighbour.second,
                        neighbour.first,
                        sum + values[neighbour.first],
                        values,
                        new_visited,
                        visited_size+1
                    );
                }
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
