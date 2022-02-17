/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 1270 ms, faster than 64.18% of C++ online submissions for Groups of Strings.
Memory Usage: 68.5 MB, less than 69.73% of C++ online submissions for Groups of Strings.
*/

// profiled

#include <bits/stdc++.h>

using namespace std;

class disjoint_set {
public:
    vector<int> parent;
    vector<int> size;

    vector<int> sum_val;
    int set_cnt;
    int max_sum_val;

    disjoint_set(int max_size) {
        parent.resize(max_size);
        size.resize(max_size);
        sum_val.resize(max_size);
        for (int i=0; i<max_size; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    disjoint_set(int max_size, vector<int>& val): sum_val(val) {
        parent.resize(max_size);
        size.resize(max_size);
        sum_val.resize(max_size);
        for (int i=0; i<max_size; ++i) {
            parent[i] = i;
            size[i] = 1;
        }

        set_cnt = max_size;
        max_sum_val = 1;
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

            sum_val[b] += sum_val[a];
            max_sum_val = max(max_sum_val, sum_val[b]);
            --set_cnt;
        }
    }
};

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

        disjoint_set ds(m, val);

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
                    ds.union_set(i, j);
                }
            }
        }

        vector<int> res = { ds.set_cnt, ds.max_sum_val };

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
