/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 1379 ms, faster than 53.38% of C++ online submissions for Groups of Strings.
Memory Usage: 84.8 MB, less than 44.45% of C++ online submissions for Groups of Strings.
*/

// profiled

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

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        bitset<26> words_b[20000];
        unordered_map<int, int> words_b_count;

        int n = words.size();
        int cnt = 0;
        for (int i=0; i<n; ++i){
            auto word_b = to_b(words[i]);
            auto mask = word_b.to_ulong();
            if (words_b_count[mask]){
                ++words_b_count[mask];
            } else {
                words_b[cnt++] = word_b;
                words_b_count[mask] = 1;
            }
        }

        sort(words_b, words_b+cnt, [](bitset<26>& i, bitset<26>& j){return i.count() < j.count();});
        
        int m = cnt;

        if (m == 1){
            vector<int> res = { 1, words_b_count[words_b[0].to_ulong()] };
            return res;
        }

        vector<int> word_length(m);
        vector<int> val(m);
        for (int i=0; i<m; ++i){
            val[i] = words_b_count[words_b[i].to_ulong()];
            word_length[i] = words_b[i].count();
        }

        graph g(m, val);

        for (int i=0; i<m; ++i){
            for (int j=i+1; j<m; ++j){
                int diff_length = word_length[j] - word_length[i];
                // rely on sorted vec
                if (diff_length > 1){
                    break;
                }
                auto diff_cnt = (words_b[i] ^ words_b[j]).count();
                if (
                    diff_cnt <= 1 || 
                    (diff_cnt == 2 && diff_length == 0)
                ){
                    g.add_edge(i, j);
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
