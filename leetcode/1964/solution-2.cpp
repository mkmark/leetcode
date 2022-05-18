/*
author: mark@mkmark.net
time: O(nlogn)
space: O(n)

Runtime: 281 ms, faster than 93.48% of C++ online submissions for Find the Longest Valid Obstacle Course at Each Position.
Memory Usage: 116.5 MB, less than 100.00% of C++ online submissions for Find the Longest Valid Obstacle Course at Each Position.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = size(obstacles);
        vector<int> result(n);
        vector<int> lis;
        // if not reserve, push_back would reallocate memory
        lis.reserve(n);
        for (int i = 0; i<n; ++i){
            auto it = upper_bound(lis.begin(), lis.end(), obstacles[i]);
            if (it == lis.end()){
                lis.push_back(obstacles[i]);
                // the following will not work should push_back reallocate memory
                result[i] = it - lis.begin() + 1;
                // but then can be safely derived using
                // result[i] = lis.size();
                // result[i] = lis.end() - lis.begin();
            } else {
                *it = obstacles[i];
                result[i] = it - lis.begin() + 1;
            }
        }
        return result;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
