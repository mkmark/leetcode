/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 8 ms, faster than 89.01% of C++ online submissions for Rectangle Area II.
Memory Usage: 10.1 MB, less than 30.42% of C++ online submissions for Rectangle Area II.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <algorithm>    // std::sort
#include <set>          // std::set
#include <map>          // std::set
#include <numeric>      // std::iota
#include "segment_tree.hpp"

using namespace std;

class Solution {
public:
    const int ON = 1;
    const int OFF = -1;
    const int mod = 1e9+7;
    long rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        // remap x
        set<int> x_pos_set;
        for (auto rec: rectangles) {
            x_pos_set.insert(rec[0]);
            x_pos_set.insert(rec[2]);
        }
        // remap actual position to compressed position
        map<long, int> x_pos_compressed;
        vector<long> x_pos_actual(x_pos_set.size());
        int i = 0;
        for (auto x_pos: x_pos_set) {
            x_pos_actual[i++] = x_pos;
        }
        sort(x_pos_actual.begin(), x_pos_actual.end());
        i = 0;
        for (auto x_pos: x_pos_set) {
            x_pos_compressed.insert(make_pair(x_pos, i++));
        }

        vector<vector<int>> events;
        int t=0;
        // sweep along y, record y and 2 x
        int x_pos_compressed_0, x_pos_compressed_1;
        for (auto rec: rectangles) {
            x_pos_compressed_0 = x_pos_compressed[rec[0]];
            x_pos_compressed_1 = x_pos_compressed[rec[2]];
            events.push_back({rec[1], ON, x_pos_compressed_0, x_pos_compressed_1});
            events.push_back({rec[3], OFF, x_pos_compressed_0, x_pos_compressed_1});
        }
        // sort events along y
        sort(events.begin(), events.end(), [](vector<int>& i, vector<int>& j){return i[0]<j[0];});
        // sort x_pos

        long area = 0;
        segment_tree::segment_tree st = segment_tree::segment_tree(x_pos_actual.size());
        long y_cur;
        long y_pre = 0;
        long y_diff;
        long length_pre = 0;
        for (auto event : events){
            y_cur = event[0];
            st.range_add(
                event[2], 
                event[3], 
                event[1], 
                1,
                0,
                x_pos_actual.size()+1,
                [&x_pos_actual](int& l, int& r){return x_pos_actual[r] - x_pos_actual[l];}
            );
            y_diff = y_cur-y_pre;
            y_pre = y_cur;
            if (y_diff){
                area += (length_pre*y_diff)%mod;
            }
            length_pre = st.top()%mod;
        }

        return area%mod;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);