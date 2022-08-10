/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 470 ms, faster than 96.01% of C++ online submissions for Minimum Obstacle Removal to Reach Corner.
Memory Usage: 120.4 MB, less than 48.41% of C++ online submissions for Minimum Obstacle Removal to Reach Corner.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

char seen[100001];

class Solution {
public:
    int m;
    int n;
    vi cur_0s, cur_1s, nxt_0s, nxt_1s;
    vvi * ptr_grd;
    int target;

    int res = 0;
    int minimumObstacles(vector<vector<int>>& grid) {
        ptr_grd = &grid;
        m = size(grid);
        n = size(grid[0]);
        target = m*n-1;
        memset(seen, 0, m*n);
        cur_0s.reserve(m*n);
        cur_1s.reserve(m*n);
        nxt_0s.reserve(m*n);
        nxt_1s.reserve(m*n);
        cur_0s.push_back(0);
        bfs_find(cur_0s);
        return res;
    }

    int hash;
    inline void push_hash(int x, int y){
        hash = x*n+y;
        if (!seen[hash]) {
            seen[hash] = 1;
            if ((*ptr_grd)[x][y]){
                nxt_1s.push_back(hash);
            } else {
                nxt_0s.push_back(hash);
            }
        }
    }

    int x,y;
    void bfs_find(vi & curs){
        for (auto & cur : curs){
            x = cur / n;
            y = cur % n;
            if (x>0) push_hash(x-1, y);
            if (y>0) push_hash(x, y-1);
            if (x<m-1) push_hash(x+1, y);
            if (y<n-1) push_hash(x, y+1);
        }
        if (seen[target]) return;
        if (size(nxt_0s)){
            swap(cur_0s, nxt_0s);
            nxt_0s.resize(0);
            bfs_find(cur_0s);
        } else if (size(nxt_1s)){
            swap(cur_1s, nxt_1s);
            nxt_1s.resize(0);
            ++res;
            bfs_find(cur_1s);
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
