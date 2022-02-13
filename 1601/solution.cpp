// Runtime: 888 ms, faster than 19.58% of C++ online submissions for StMaximum Number of Achievable Transfer Requests.
// Memory Usage: 214.5 MB, less than 6.99% of C++ online submissions for StMaximum Number of Achievable Transfer Requests.

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <numeric>      // std::accumulate

using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> inflow(n,0);
        return dfs(requests, 0, inflow);
    }
    int dfs(vector<vector<int>>& requests, int i, vector<int> &inflow){
        if (i>=requests.size()){
            if (is_all_0(inflow)){
                return 0;
            } else {
                return INT32_MIN;
            }
        }
        vector<int> inflow_with_i = inflow;
        --inflow_with_i[requests[i][0]];
        ++inflow_with_i[requests[i][1]];
        return max(
            dfs(requests, i+1, inflow),
            1+dfs(requests, i+1, inflow_with_i)
        );
    }
    bool is_all_0(vector<int>& arr){
        for (auto i : arr){
            if (i) return false;
        }
        return true;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
