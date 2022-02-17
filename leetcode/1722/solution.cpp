/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 443 ms, faster than 71.33% of C++ online submissions for Minimize Hamming Distance After Swap Operations.
Memory Usage: 127.4 MB, less than 89.08% of C++ online submissions for Minimize Hamming Distance After Swap Operations.
*/

#include <bits/stdc++.h>
using namespace std;

class disjoint_set {
public:
    vector<int> parent;
    vector<int> size;

    disjoint_set(int max_size) {
        parent.resize(max_size);
        size.resize(max_size);
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
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int m = allowedSwaps.size();

        disjoint_set ds(n);
        for (int i=0; i<m; ++i){
            ds.union_set(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        vector<int> idx_2_sid(n);
        unordered_map<int,multiset<int>> sid_2_source_num;
        int sid;
        for (int i=0; i<n; ++i){
            sid = ds.get_set(i);
            idx_2_sid[i] = sid;
            sid_2_source_num[sid].insert(source[i]);
        }

        int res = 0;
        for (int i=0; i<n; ++i){
            auto target_num = target[i];
            auto sid = idx_2_sid[i];
            auto it = sid_2_source_num[sid].find(target_num);
            if (it == sid_2_source_num[sid].end()){
                ++res;
            } else {
                sid_2_source_num[sid].erase(it);
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
