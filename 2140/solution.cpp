// Runtime: 260 ms, faster than 99.93% of C++ online submissions for Solving Questions With Brainpower.
// Memory Usage: 124.1 MB, less than 15.57% of C++ online submissions for Solving Questions With Brainpower.

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // dp[i]
        vector<long long> dp(n, -1);
        return dfs(dp, questions, 0);
    }
    long long dfs(vector<long long>& dp, vector<vector<int>>& questions, int i){
        if (i>=questions.size())
            return 0;
        if (dp[i]>-1)
            return dp[i];
        else
            return dp[i] = max(
                dfs(dp, questions, i+1),
                questions[i][0] + dfs(dp, questions, i+questions[i][1]+1)
            );
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
