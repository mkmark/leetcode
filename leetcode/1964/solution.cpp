/*
author: mark@mkmark.net
time: O(nlogn)
space: O(n)

Runtime: 220 ms, faster than 100.00% of C++ online submissions for Find the Longest Valid Obstacle Course at Each Position.
Memory Usage: 115.5 MB, less than 100.00% of C++ online submissions for Find the Longest Valid Obstacle Course at Each Position.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = size(obstacles);
        vector<int> result(n);
        int lis[n];
        int * lis_end = lis;
        for (int i = 0; i<n; ++i){
            auto it = upper_bound(lis, lis_end, obstacles[i]);
            *it = obstacles[i];
            if (it == lis_end){
                ++lis_end;
            }
            result[i] = it - lis + 1;
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
