/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <algorithm>    // std::sort

using namespace std;

class Solution {
public:
    const int UNKOWN = 0;
    const int SEEN = 1;
    const int LOOP_2 = 2;
    const int LOOP_L = 3;
    const int LEAF = 4;

    int maximumInvitations(vector<int>& favorites) {
        int n = favorites.size();

        // initialize
        vector<int> popularities(n);
        for (auto favorite : favorites){
            popularities[favorite]++;
        }

        int max_loop_size = 0;
        // record position
        vector<int> pos(n);
        vector<int> status(n);
        for (int i=0;i<n;++i){
            // all local group point to same loop
            vector<int> local_group;
            // start from dead end
            if (popularities[i] == 0){
                int now = i;
                pos[now] = 1;
                local_group.push_back(now);
                int next = favorites[now];
                while (status[next] == UNKOWN){
                    pos[next] = pos[now] + 1;
                    now = next;
                    status[now] = SEEN;
                    local_group.push_back(now);
                    next = favorites[now];
                }
                if (status[next] == SEEN){
                    int loop_size = pos[now] + 1 - pos[next];
                    max_loop_size = max(max_loop_size, loop_size);
                    if (loop_size == 2){
                        for (int j=0;j<local_group.size()-2;++j){
                            status[local_group[j]] = LEAF;
                        }
                        status[now] = LOOP_2;
                        pos[now] = 1;
                        status[next] = LOOP_2;
                    } else {
                        for (int j=0;j<local_group.size();++j){
                            status[local_group[j]] = LOOP_L;
                        }
                    }
                } else if (status[next] == LEAF){
                    for (int j=0;j<local_group.size();++j){
                        status[local_group[j]] = LEAF;
                    }
                    // bottle neck, is targeted by test case 90, 20220131
                    // the algorithm will update the branch with a lot of redundant work if the actual long branch shows up late
                    while (status[next] == LEAF){
                        if (pos[now] + 1 > pos[next]){
                            pos[next] = pos[now] + 1;
                        }
                        now = next;
                        next = favorites[now];
                    }
                    if (pos[now] + 1 > pos[next]){
                        pos[next] = pos[now] + 1;
                    }

                } else if (status[next] == LOOP_2){
                    pos[next] = max(pos[now] + 1, pos[next]);
                    for (int j=0;j<local_group.size();++j){
                        status[local_group[j]] = LEAF;
                    }
                } else {
                    // LOOP_L
                    for (int j=0;j<local_group.size();++j){
                        status[local_group[j]] = LOOP_L;
                    }
                    continue;
                }
            }
        }

        // closed loops
        for (int i=0;i<n;++i){
            if (pos[i]) {
                continue;
            }
            int loop_size = 0;
            int now = i;
            int next = favorites[now];
            while (status[next] == UNKOWN){
                now = next;
                status[now] = LOOP_L;
                next = favorites[now];
                pos[now] = 1;
                ++loop_size;
            }
            max_loop_size = max(max_loop_size, loop_size);
            if (loop_size == 2){
                status[now] = LOOP_2;
                status[next] = LOOP_2;
            }
        }

        // sum the couples
        int sum_couple_length = 0;
        for (int i=0;i<n;++i){
            if (status[i] == LOOP_2){
                sum_couple_length += pos[i];
            }
        }

        return max(max_loop_size, sum_couple_length);
    }
};