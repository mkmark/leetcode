/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 852 ms, faster than 23.14% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.
Memory Usage: 120.3 MB, less than 8.83% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include "math.h"

using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int n = s.length();
        int max_product = -1;

        for (int i=0;i<pow(2,n-1);++i){
            string s1 = "";
            string s2 = "";
            int x = i;
            int p = 0;
            while(x != 0){
                if (x%2){
                    s1.push_back(s.at(p++));
                } else {
                    s2.push_back(s.at(p++));
                }
                x >>= 1;
            }
            for (p;p<n;++p){
                s2.push_back(s.at(p));
            }
            max_product = max(
                max_product,
                max_sub_palindrome_length(s1)*max_sub_palindrome_length(s2)
            );
        }
        return max_product;
    }

    int max_sub_palindrome_length(string &s){
        int n = s.length();
        if (n==0){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i=n-1; i>=0; --i){
            dp[i][i] = 1;
            for (int j=i+1; j<n; ++j){
                if (s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }   
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
