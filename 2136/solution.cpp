#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <algorithm>    // std::sort
#include <numeric>      // std::iota

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // plant in the descending order of growTime to maximize saved (overlapping) time
        int n = plantTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i,int j){return growTime[i]>growTime[j];});
        int max_time = 0;
        int previous_plant = 0;
        int current_plant;
        int current_idx;
        for (int i=0;i<n;++i){
            current_idx = idx[i];
            current_plant = previous_plant+plantTime[current_idx];
            previous_plant = current_plant;
            max_time = max(max_time, current_plant+growTime[current_idx]);
        }
        return max_time;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);