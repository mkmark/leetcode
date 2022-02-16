/*
author: mark@mkmark.net
time: O(mn^2)
space: O()

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Substrings That Differ by One Character.
Memory Usage: 6.3 MB, less than 49.70% of C++ online submissions for Count Substrings That Differ by One Character.
*/

// brutal force

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int s_length = s.length();
        int t_length = t.length();
        int res = 0;
        for (int i=0; i<s_length; ++i){
            for (int j=0; j<t_length; ++j){
                res += dfs_cnt_sub_str(s,t,i,j,0);
            }
        }
        return res;
    }

    int dfs_cnt_sub_str(
        string& s, 
        string& t,
        int i, 
        int j,
        int diff_cnt
    ){
        // reach end
        if (i==s.length() || j==t.length()){
            return 0;
        }

        if (diff_cnt==2){
            return 0;
        } else if (diff_cnt==1){
            if (s[i]==t[j]){
                return 1 + dfs_cnt_sub_str(s, t, i+1, j+1, 1);
            } else {
                return 0;
            }
        } else {
            if (s[i]==t[j]){
                return dfs_cnt_sub_str(s, t, i+1, j+1, 0);
            } else {
                return 1 + dfs_cnt_sub_str(s, t, i+1, j+1, 1);
            }
        }
    }

};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
