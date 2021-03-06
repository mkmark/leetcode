/*
author: mark@mkmark.net
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
            if (size[a] > size[b])
                swap(a, b);
            parent[a] = b;
            size[b] += size[a];
        }
    }
};
