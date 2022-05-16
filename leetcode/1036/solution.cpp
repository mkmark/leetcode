/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 364 ms, faster than 66.84% of C++ online submissions for Escape a Large Maze.
Memory Usage: 73.4 MB, less than 57.00% of C++ online submissions for Escape a Large Maze.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int DIM = 397;
    static const int CENTER = 198;
    // possible range is actually a diamond shape, put source at visited[198][198]
    char visited[DIM][DIM];

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        init_visited(blocked, source);
        int source_result = bfs(source, target);
        if (source_result == 0){
            // true
            return true;
        } else if (source_result == 1){
            // impossible
            return false;
        } else {
            // possible
            init_visited(blocked, target);
            return bfs(target, source) == 2;
        }
    }

    bool in_range(pair<int, int> pos){
        return n_in_range(pos.first) && n_in_range(pos.second);
    }

    bool n_in_range(int n){
        return 0<=n && n<DIM;
    }

    int x_translate(int x, vector<int>& s){
        return x - s[0] + CENTER;
    }

    int y_translate(int y, vector<int>& s){
        return y - s[1] + CENTER;
    }

    pair<int, int> translate(vector<int>& pos, vector<int>& s){
        return make_pair(x_translate(pos[0], s), y_translate(pos[1], s));
    }

    void init_visited(vector<vector<int>>& blocked, vector<int>& s){
        memset(visited, 0, sizeof visited);
        pair<int, int> pos;
        for (auto blocked_pos : blocked){
            pos = translate(blocked_pos,s);
            if (in_range(pos)){
                visited[pos.first][pos.second] = 2;
            }
            int lb = y_translate(-1, s);
            int rb = y_translate(1000000, s);
            int tb = x_translate(-1, s);
            int bb = x_translate(1000000, s);
            if (n_in_range(lb)){
                for (int i = 0; i < DIM; ++i){
                    visited[i][lb] = 3;
                }
            }
            if (n_in_range(rb)){
                for (int i = 0; i < DIM; ++i){
                    visited[i][rb] = 3;
                }
            }
            if (n_in_range(tb)){
                for (int i = 0; i < DIM; ++i){
                    visited[tb][i] = 3;
                }
            }
            if (n_in_range(bb)){
                for (int i = 0; i < DIM; ++i){
                    visited[bb][i] = 3;
                }
            }
        }
    }

    int bfs(vector<int>& s, vector<int>& t){
        queue<pair<int, int>> poses_cur, poses_next;
        pair<int, int> pos_cur = translate(s, s);
        pair<int, int> pos_next;
        pair<int, int> pos_target = translate(t, s);
        poses_cur.push(pos_cur);
        visited[pos_cur.first][pos_cur.second] = 1;
        const vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int range = 0;
        int block_met = 0;
        while(range<=CENTER){
            while(!poses_cur.empty()){
                pos_cur = poses_cur.front();
                poses_cur.pop();
                visited[pos_cur.first][pos_cur.second] = 1;
                for (auto dir : dirs){
                    pos_next = make_pair(pos_cur.first+dir[0], pos_cur.second+dir[1]);
                    if (!in_range(pos_next)){
                        continue;
                    }
                    if (pos_next.first == pos_target.first && pos_next.second == pos_target.second){
                        // true
                        return 0;
                    }
                    if (!visited[pos_next.first][pos_next.second]){
                        poses_next.push(pos_next);
                        visited[pos_next.first][pos_next.second] = 1;
                    }
                    else if (visited[pos_next.first][pos_next.second] == 2){
                        block_met ++;
                    }
                }
            }
            if (poses_next.size() > 200 - block_met){
                // possible
                return 2;
            }
            swap(poses_cur, poses_next);
            ++range;
        }
        if (poses_cur.empty()){
            // impossible
            return 1;
        }
        // possible
        return 2;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
