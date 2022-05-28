/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 606 ms, faster than 95.00% of C++ online submissions for Checking Existence of Edge Length Limited Paths.
Memory Usage: 120.1 MB, less than 25.91% of C++ online submissions for Checking Existence of Edge Length Limited Paths.
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

template<class T>
class DisjointSet {
public:
    /// array
    static const int MAX_SIZE = 100000;
    T parent[MAX_SIZE];
    T union_size[MAX_SIZE];
    ///

    /// vector
    // vector<T> parent;
    // vector<T> union_size;
    ///

    DisjointSet(int max_size) {
        /// array
        iota(parent, parent+max_size, 0);
        fill(union_size, union_size+max_size, 1);
        ///

        /// vector
        // parent.resize(max_size);
        // union_size.resize(max_size);
        // iota(begin(parent), end(parent), 0);
        // fill(begin(union_size), end(union_size), 1);
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // map distance to start-end pair
        multimap<int, array<int,3>> mm;
        int queries_size = size(queries);
        for (int i=0; i<queries_size; ++i){
            mm.insert({queries[i][2], {queries[i][0], queries[i][1], i}});
        }
        sort(all(edgeList), [](vi& e0, vi& e1){return e0[2] < e1[2];});
        auto ds = DisjointSet<int>(n);

        int edgeList_i = 0;
        int edgeList_size = size(edgeList);
        vector<bool> ans(queries_size);
        for (auto &q: mm){
            while(edgeList_i<edgeList_size && edgeList[edgeList_i][2]<q.first){
                ds.union_set(edgeList[edgeList_i][0], edgeList[edgeList_i][1]);
                ++edgeList_i;
            }
            ans[q.second[2]] = ds.get_set(q.second[0]) == ds.get_set(q.second[1]);
        }
        return ans;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
