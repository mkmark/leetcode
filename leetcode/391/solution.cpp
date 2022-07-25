/*
author: mark@mkmark.net
time: O(nlog(n))
space: O(n)

Runtime: 129 ms, faster than 94.04% of C++ online submissions for Perfect Rectangle.
Memory Usage: 37.9 MB, less than 20.00% of C++ online submissions for Perfect Rectangle.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        /// stream[y] = { open_map, close_map }
        /// x_map[x1] = x2
        map<int, array<map<int, int>, 2>> stream;
        for (auto & rect : rectangles){
            if (stream[rect[1]][0].find(rect[0]) != stream[rect[1]][0].end() && stream[rect[1]][0][rect[0]] == rect[2]) return false;
            stream[rect[1]][0].insert({rect[0], rect[2]});
            stream[rect[3]][1].insert({rect[0], rect[2]});
        }

        /// merge bottom
        if (!merge_ranges((*begin(stream)).second[0])) return false;
        /// bottom check
        if ((*stream.begin()).second[0].size() != 1) return false;
        /// merge top
        if (!merge_ranges((*rbegin(stream)).second[1])) return false;
        /// top check
        if ((*rbegin(stream)).second[1] != (*begin(stream)).second[0]) return false;
        /// middle check
        auto it_end = prev((stream.end()));
        for (auto it = next(stream.begin()); it != it_end; ++it){
            if (!merge_ranges((*it).second[0])) return false;
            if (!merge_ranges((*it).second[1])) return false;
            if ((*it).second[0] != (*it).second[1]) return false;
        }

        return true;
    }

    inline bool merge_ranges(std::map<int, int> & ranges){
        /// empty range does not equal nonempty ones, but would cause infinite loop
        if (ranges.empty()) return false;
        auto former = begin(ranges);
        auto cur = next(begin(ranges));
        map<int, int>::iterator to_erase;
        while (cur != end(ranges)){
            if ((*cur).first == (*former).second){
                (*former).second = (*cur).second;
                to_erase = cur++;
                ranges.erase(to_erase);
            } else if ((*cur).first < (*former).second){
                return false;
            } else {
                former = cur;
                ++cur;
            }
        }
        return true;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
