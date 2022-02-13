// Runtime: 591 ms, faster than 39.14% of C++ online submissions for Maximum Employees to Be Invited to a Meeting.
// Memory Usage: 188.5 MB, less than 25.05% of C++ online submissions for Maximum Employees to Be Invited to a Meeting.

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

    int maximumInvitations(vector<int>& likes) {
        int n = likes.size();

        // record position
        vector<int> pos(n);
        vector<int> status(n);

        int max_loop_size = 0;

        vector<int> couples;
        // find couples
        for (int i=0;i<n;++i){
            if (status[i]){
                continue;
            }
            int likes_i = likes[i];
            if (likes[likes_i] == i){
                max_loop_size = 2;
                status[likes_i] = LOOP_2;
                status[i] = LOOP_2;
                couples.push_back(i);
                couples.push_back(likes_i);
            }
        }

        // identify simps
        vector<vector<int>> simps(n);
        for (int i=0;i<n;++i){
            simps[likes[i]].push_back(i);
        }

        // find simps chain from couples
        for (int i=0;i<couples.size();++i){
            int max_simp_level = 0;
            int person = couples[i];
            for (int simp : simps[person]){
                if (simp == likes[person]){
                    continue;
                }
                max_simp_level = max(max_simp_level, get_simp_level(simp, simps, status));
            }
            pos[person] = max_simp_level+1;
        }

        // loops
        for (int i=0;i<n;++i){
            if (pos[i]) {
                continue;
            }
            vector<int> local_group;
            pos[i] = 1;
            int now = i;
            local_group.push_back(now);
            int next = likes[now];
            while (status[next] == UNKOWN){
                pos[next] = pos[now] + 1;
                now = next;
                local_group.push_back(now);
                status[now] = SEEN;
                next = likes[now];
            }
            if (status[next] == SEEN){
                int loop_size = pos[now] + 1 - pos[next];
                max_loop_size = max(max_loop_size, loop_size);
            }
            for (int j=0;j<local_group.size();++j){
                status[local_group[j]] = LOOP_L;
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

    int get_simp_level(
        int i,
        vector<vector<int>>& simps,
        vector<int>& status
    ){
        status[i] = LEAF;
        if (simps[i].size()==0){
            return 1;
        } else {
            int max_simp_level = 0;
            for (int j : simps[i]){
                max_simp_level = max(max_simp_level, get_simp_level(j, simps, status));
            }
            return max_simp_level+1;
        }
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);