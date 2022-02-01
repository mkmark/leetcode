#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <algorithm>    // std::sort
#include <queue>        // std::priority_queue

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](vector<int>& i,vector<int>& j){return i[1]<j[1];});
        
        int sum_duration = 0;
        int course_count = 0;
        int proposed_sum_duration;
        int cur_duration;
        priority_queue<int> taken_duration;
        for (int i=0;i<courses.size();++i){
            cur_duration = courses[i][0];
            proposed_sum_duration = sum_duration + cur_duration;
            taken_duration.push(cur_duration);
            if (proposed_sum_duration > courses[i][1]){
                // delete the course taken with longest duration
                sum_duration = proposed_sum_duration - taken_duration.top();
                taken_duration.pop();
            } else {
                sum_duration = proposed_sum_duration;
                ++course_count;
            }
        }
        return course_count;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);