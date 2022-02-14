/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 22 ms, faster than 100.00% of C++ online submissions for Minimum Number of Flips to Make the Binary String Alternating.
Memory Usage: 11.6 MB, less than 75.97% of C++ online submissions for Minimum Number of Flips to Make the Binary String Alternating.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        int count_a = 0;
        int count_b = 0;
        if (n%2==0){
            for (int i=0;i<n;++i){
                if ((i%2) ^ (s[i] == '0')){
                    ++count_a;
                } else {
                    ++count_b;
                }
            }
            return min(count_a, count_b);
        } else {
            // vector<int> count_a_sum(n);
            // vector<int> count_b_sum(n);
            // for(int i=0;i<n;++i){
            //     if ((i%2) ^ (s[i] == '0')){
            //         count_a_sum[i] = ++count_a;
            //         count_b_sum[i] = count_b;
            //     } else {
            //         count_a_sum[i] = count_a;
            //         count_b_sum[i] = ++count_b;
            //     }
            // }
            // int res = min(count_a, count_b);
            // for(int i=0;i<n;++i){
            //     res = min(
            //         res,
            //         count_a_sum[i] + count_b - count_b_sum[i]
            //     );
            //     res = min(
            //         res,
            //         count_b_sum[i] + count_a - count_a_sum[i]
            //     );
            // }
            // return res;

            // same as above but faster and less memory
            int res_a_b = 0;
            int res_b_a = 0;
            for(int i=0;i<n;++i){
                if ((i%2) ^ (s[i] == '0')){
                    ++count_a;
                    res_b_a = min(res_b_a, count_b-count_a);
                } else {
                    ++count_b;
                    res_a_b = min(res_a_b, count_a-count_b);
                }
            }
            return min(
                res_b_a+count_a,
                res_a_b+count_b
            );
        }
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
