/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 132 ms, faster than 100.00% of C++ online submissions for Graph Connectivity With Threshold.
Memory Usage: 64.5 MB, less than 98.22% of C++ online submissions for Graph Connectivity With Threshold.
*/

#include <bits/stdc++.h>
using namespace std;

class disjoint_set {
public:
    // vector<int> parent;
    int parent[10001];
    // vector<int> size;
    int size[10001];
   
    disjoint_set(int max_size) {
        // parent.resize(max_size);
        // size.resize(max_size);
        for (int i=0; i<max_size; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
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
            if (size[a] > size[b])
                swap(a, b);
            parent[a] = b;
            size[b] += size[a];
        }
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int q_size = queries.size();
        vector<bool> res(q_size);

        disjoint_set ds(n+1);

        for (int i=threshold+1; i<=n/2; ++i){
            for (int j=i; j<=n; j+=i){
                ds.union_set(i, j);
            }
        }

        for (int i=0; i<q_size; ++i){
            if (ds.get_set(queries[i][0]) == ds.get_set(queries[i][1])){
                res[i] = true;
            }
        }

        return res;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
