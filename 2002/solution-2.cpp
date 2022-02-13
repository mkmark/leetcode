// Runtime: 3 ms, faster than 99.65% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.
// Memory Usage: 6.1 MB, less than 45.94% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.

// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/discuss/1458289/Mask-DP

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    /**
     *  @brief if masked string is a palindrome, return its length; else return 0.
     */
    int palindrome_length(string &s, int mask) {
        int p1 = 0, p2 = s.size(), res = 0;
        while (p1 <= p2) {
            if ((mask & (1 << p1)) == 0)
                ++p1;
            else if ((mask & (1 << p2)) == 0)
                --p2;
            else if (s[p1] != s[p2])
                return 0;
            else
                res += 1 + (p1++ != p2--);
        }
        return res;
    }
    int maxProduct(string s) {
        int dp[4096];
        int res = 0;
        int mask = (1 << s.size()) - 1;
        // get all palindrome_length
        for (int m = 1; m <= mask; ++m){
            dp[m] = palindrome_length(s, m);
        }
        for (int m1 = mask; m1; --m1){
            // pruning to skip masks with no potential to surpass the current maximum
            if (dp[m1] * (s.size() - dp[m1]) > res){
                // check only "available" bits (mask ^ m1)
                for(int m2 = mask ^ m1; m2; m2 = (m2 - 1) & (mask ^ m1)){
                    res = max(res, dp[m1] * dp[m2]);
                }
            }
        }
        return res;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
