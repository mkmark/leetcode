/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 1600 ms, faster than 36.15% of C++ online submissions for Groups of Strings.
Memory Usage: 87.2 MB, less than 43.10% of C++ online submissions for Groups of Strings.
*/

// mem same word

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
    void add_edge(int i, int j, int val_i, int val_j);
    void group();
};

graph::graph(int n): n(n){
    adj.resize(n);
    grp.resize(n);
    value.resize(n);
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
    }return res;
}
 
void graph::dfs(int i, vector<int>& grp, int gid){
    grp[i] = gid;
    grp_size[gid] += value[i];
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

void graph::add_edge(int i, int j, int val_i, int val_j){
    adj[i].push_back(j);
    adj[j].push_back(i);
    value[i] = val_i;
    value[j] = val_j;
}

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        vector<bitset<26>> words_b;
        unordered_map<int, int> words_b_count;

        int n = words.size();

        for (int i=0; i<n; ++i){
            auto word_b = to_b(words[i]);
            auto mask = word_b.to_ulong();
            auto t = words_b_count.find(mask);
            if (words_b_count[mask]){
                ++words_b_count[mask];
            } else {
                words_b.push_back(word_b);
                words_b_count[mask] = 1;
            }
        }

        sort(words_b.begin(), words_b.end(), [](bitset<26>& i, bitset<26>& j){return i.count() < j.count();});

        int m = words_b.size();

        if (m == 1){
            vector<int> res = { 1, words_b_count[words_b[0].to_ulong()] };
            return res;
        }

        graph g(m);

        for (int i=0; i<m; ++i){
            for (int j=i+1; j<m; ++j){
                int diff_length = abs((int)(words_b[j].count() - words_b[i].count()));
                // rely on sorted vec
                if (diff_length > 1){
                    break;
                }
                auto diff_cnt = (words_b[i] ^ words_b[j]).count();
                if (
                    diff_cnt <= 1 || 
                    (diff_cnt == 2 && diff_length == 0)
                ){
                    g.add_edge(i, j, words_b_count[words_b[i].to_ulong()], words_b_count[words_b[j].to_ulong()]);
                }
            }
        }

        g.group();

        vector<int> res = { g.grp_cnt, g.max_grp_size() };
        return res;
    }

    inline bitset<26> to_b(string word){
        bitset<26> b;
        for (auto c : word) {
            b |= (1<<(c-'a'));
        }
        return b;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
