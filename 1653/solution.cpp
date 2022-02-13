// Runtime: 36 ms, faster than 100.00% of C++ online submissions for Minimum Deletions to Make String Balanced.
// Memory Usage: 22.1 MB, less than 67.50% of C++ online submissions for Minimum Deletions to Make String Balanced.

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int count_b = 0;
        int count_a = 0;
        // vector<int> count_bs(n, 0);
        // vector<int> count_as(n, 0);
        // for (int i=0; i<n; ++i){
        //     if (s[i] == 'a'){
        //         count_as[i] = ++count_a;
        //         count_bs[i] = count_b;
        //     } else {
        //         count_as[i] = count_a;
        //         count_bs[i] = ++count_b;
        //     }
        // }
        // int res = min(count_a, count_b);
        // for (int i=0; i<n; ++i){
        //     res = min(
        //         res,
        //         count_bs[i] + count_a - count_as[i]
        //     );
        // }
        // return res;

        // same as above but faster
        int res_b_a = 0;
        for (int i=0; i<n; ++i){
            if (s[i] == 'a'){
                ++count_a;
            } else {
                ++count_b;
            }
            res_b_a = min(
                res_b_a,
                count_b - count_a
            );
        }
        return res_b_a + count_a;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
