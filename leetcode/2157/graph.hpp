/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>
using namespace std;

class graph {
    int n;
    vector<vector<int>> adj;
    vector<int> grp;
    vector<int> grp_size;
    vector<int> value;
    void dfs(int v, vector<int>& grp, int gid);
 
public:
    graph(int n);
    graph(int n, vector<int>& val);
    int grp_cnt;
    int max_grp_size();
    void add_edge(int i, int j);
    void group();
};
