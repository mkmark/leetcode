/*
author: mark@mkmark.net
*/

#include "graph.hpp"
using namespace std;

graph::graph(int n): n(n){
    adj.resize(n);
    grp.resize(n);
    fill_n(grp.begin(), n, -1);
}

graph::graph(int n, vector<int>& val): n(n){
    adj.resize(n);
    grp.resize(n);
    fill_n(grp.begin(), n, -1);
    value = val;
}

void graph::group(){
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

int graph::max_grp_size(){
    int res = 0;
    for (int i=0; i<grp_cnt; ++i) {
        res=max(res, grp_size[i]);
    }
    return res;
}
 
void graph::dfs(int i, vector<int>& grp, int gid){
    grp[i] = gid;
    for (auto j : adj[i]){
        if (grp[j] == -1){
            dfs(j, grp, gid);
        }
    }
}

void graph::add_edge(int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}
