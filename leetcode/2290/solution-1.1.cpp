/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 233 ms, faster than 100.00% of C++ online submissions for Minimum Obstacle Removal to Reach Corner.
Memory Usage: 87.9 MB, less than 100.00% of C++ online submissions for Minimum Obstacle Removal to Reach Corner.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int MAX_MN = 100001;
char seen[MAX_MN];
int cur_0s[MAX_MN], cur_1s[MAX_MN], nxt_0s[MAX_MN], nxt_1s[MAX_MN];
int * ptr_cur_0s = cur_0s;
int * ptr_cur_1s = cur_1s;
int * ptr_nxt_0s = nxt_0s;
int * ptr_nxt_1s = nxt_1s;
int cur_0s_size, cur_1s_size, nxt_0s_size, nxt_1s_size;

class Solution {
public:
    int m;
    int n;
    int target;

    int minimumObstacles(vector<vector<int>>& grid) {
        m = size(grid);
        n = size(grid[0]);
        target = m*n-1;
        memset(seen, 0, m*n);
        cur_0s[0] = 0;
        cur_0s_size = 1;
        cur_1s_size = 0;
        nxt_0s_size = 0;
        nxt_1s_size = 0;
        int res = 0;
        bfs_find(cur_0s, cur_0s_size, res, grid);
        return res;
    }

    inline void push_hash(int x, int y, vvi & grid){
        int hash = x*n+y;
        if (!seen[hash]) {
            seen[hash] = 1;
            if (grid[x][y]){
                ptr_nxt_1s[nxt_1s_size++] = hash;
            } else {
                ptr_nxt_0s[nxt_0s_size++] = hash;
            }
        }
    }

    void bfs_find(int * curs, int & curs_size, int & res, vvi & grid){
        for (int i = 0; i<curs_size; ++i){
            int x = curs[i] / n;
            int y = curs[i] % n;
            if (x>0) push_hash(x-1, y, grid);
            if (y>0) push_hash(x, y-1, grid);
            if (x<m-1) push_hash(x+1, y, grid);
            if (y<n-1) push_hash(x, y+1, grid);
        }
        if (seen[target]) return;
        if (nxt_0s_size){
            swap(ptr_cur_0s, ptr_nxt_0s);
            swap(cur_0s_size, nxt_0s_size);
            nxt_0s_size = 0;
            bfs_find(ptr_cur_0s, cur_0s_size, res, grid);
        } else if (nxt_1s_size){
            swap(ptr_cur_1s, ptr_nxt_1s);
            swap(cur_1s_size, nxt_1s_size);
            nxt_1s_size = 0;
            ++res;
            bfs_find(ptr_cur_1s, cur_1s_size, res, grid);
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
