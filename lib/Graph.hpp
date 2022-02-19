/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;
    vector<int> grp;
    vector<int> grp_size;
    vector<int> value;
    void dfs(int v, vector<int>& grp, int gid);
 
public:
    Graph(int n);
    Graph(int n, vector<int>& val);
    int grp_cnt;
    int max_grp_size();
    void add_edge(int i, int j);
    void group();
};

Graph::Graph(int n): n(n){
    adj.resize(n);
    grp.resize(n);
    fill_n(grp.begin(), n, -1);
}

Graph::Graph(int n, vector<int>& val): n(n){
    adj.resize(n);
    grp.resize(n);
    fill_n(grp.begin(), n, -1);
    value = val;
}

void Graph::group(){
    int gid = -1;
 
    for (int i=0; i<n; ++i) {
        if (grp[i] == -1) {
            ++gid;
            grp_size.push_back(0);
            dfs(i, grp, gid);
        }
    }
 
    grp_cnt = gid+1;
}

int Graph::max_grp_size(){
    int res = 0;
    for (int i=0; i<grp_cnt; ++i) {
        res=max(res, grp_size[i]);
    }
    return res;
}
 
void Graph::dfs(int i, vector<int>& grp, int gid){
    grp[i] = gid;
    for (auto j : adj[i]){
        if (grp[j] == -1){
            dfs(j, grp, gid);
        }
    }
}

void Graph::add_edge(int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}
