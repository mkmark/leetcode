/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 230 ms, faster than 92.29% of C++ online submissions for Bus Routes.
Memory Usage: 54.6 MB, less than 74.89% of C++ online submissions for Bus Routes.

bfs
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (target==source) return 0;
        int visited[1000000] = {};
        int taken[500] = {};
        unordered_map<int, vector<int>> has_bus;
        for (int i = 0; i < size(routes); ++i){
            for (auto stop : routes[i]){
                has_bus[stop].push_back(i);
            }
        }
        queue<int> to_take;
        queue<int> to_take_next;
        for (auto bus : has_bus[source]){
            to_take.push(bus);
            taken[bus] = 1;
        }
        visited[source] = 1;
        int res = 1;
        while (!to_take.empty()){
            int bus = to_take.front();
            for (auto stop : routes[bus]){
                if (stop == target){
                    return res;
                }
                if (!visited[stop]){
                    visited[stop] = 1;
                    for (auto bus : has_bus[stop]){
                        if (!taken[bus]) {
                            taken[bus] = 1;
                            to_take_next.push(bus);
                        }
                    }
                }
            }
            to_take.pop();
            if (to_take.empty()){
                swap(to_take, to_take_next);
                ++res;
            }
        }
        return -1;
    }
};
const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
