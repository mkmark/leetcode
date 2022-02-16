/*
author: mark@mkmark.net
time: O(n^2)
space: O()

Runtime: TLE
Memory Usage: 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(string s) {
        int max_cost = 0;
        int n = s.length();
        vector<int> accu(n+1);
        for (int i=0; i<s.length(); ++i){
            accu[i+1] = accu[i] + (s[i]=='1');
        }
        int res = numeric_limits<int>::max();
        for (int i=0; i<n; ++i){
            for (int j=i; j<n; ++j){
                res = min(
                    res,
                    i + n-1-j + 2*(accu[j+1] - accu[i])
                );
            }
        }
        return res;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
