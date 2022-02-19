/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    // const int MAX_SIZE = 10000;
    // int parent[MAX_SIZE];
    vector<int> parent;
    // int size[MAX_SIZE];
    vector<int> size;

    DisjointSet(int max_size) {
        //
        parent.resize(max_size);
        //
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
