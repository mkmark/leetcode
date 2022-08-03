/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 135 ms, faster than 99.72% of C++ online submissions for Bus Routes.
Memory Usage: 45.2 MB, less than 91.40% of C++ online submissions for Bus Routes.

bfs + union set
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template<class T>
class DisjointSet {
public:
    /// array
    // static const int MAX_SIZE = 1000000;
    // T parent[MAX_SIZE];
    // T union_size[MAX_SIZE];
    ///

    /// vector
    vector<T> parent;
    vector<T> union_size;
    ///

    DisjointSet(int max_size) {
        /// array
        // iota(parent, parent+max_size, 0);
        // fill(union_size, union_size+max_size, 1);
        ///

        /// vector
        parent.resize(max_size);
        union_size.resize(max_size);
        iota(begin(parent), end(parent), 0);
        fill(begin(union_size), end(union_size), 1);
        ///
    }

    int get_set(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = get_set(parent[x]);
    }

    void union_set(int a, int b) {
        a = get_set(a);
        b = get_set(b);
        if (a != b) {
            if (union_size[a] < union_size[b]){
                swap(a, b);
            }
            parent[b] = a;
            union_size[a] += union_size[b];
        }
    }
};

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (target==source) return 0;

        int n = size(routes);
        int m = 0;
        for (auto route : routes){
            m = max(m, *max_element(all(route)));
        }
        if (source>m || target>m){
            return -1;
        }
        DisjointSet<int> ds(m+1);
        for (int i = 0; i < n; ++i){
            for (int j = 1; j < routes[i].size(); ++j){
                ds.union_set(routes[i][j-1], routes[i][j]);
            }
        }
        if (ds.get_set(source) != ds.get_set(target)){
            return -1;
        }

        int visited[1000000] = {};
        int taken[500] = {};
        unordered_map<int, vector<int>> has_bus;
        for (int i = 0; i < n; ++i){
            for (auto stop : routes[i]){
                has_bus[stop].push_back(i);
            }
        }
        stack<int> to_take;
        stack<int> to_take_next;
        for (auto bus : has_bus[source]){
            to_take.push(bus);
            taken[bus] = 1;
        }
        visited[source] = 1;
        int res = 1;
        while (!to_take.empty()){
            int bus = to_take.top();
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
