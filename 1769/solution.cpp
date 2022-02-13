// Runtime: 7 ms, faster than 88.19% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.
// Memory Usage: 8.9 MB, less than 90.32% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int op_0 = 0;
        int n = boxes.length();
        int count = boxes[0] == '1';
        for (int i=1; i<n; ++i){
            if (boxes[i] == '1'){
                op_0 += i;
                ++count;
            }
        }
        vector<int> ops(n, 0);
        ops[0] = op_0;
        int left = 0;
        int right = count;
        if (boxes[0] == '1'){
            --right;
            ++left;
        }
        for (int i=1; i<n; ++i){
            if (boxes[i] == '1'){
                ops[i] = ops[i-1] + left - right;
                --right;
                ++left;
            } else {
                ops[i] = ops[i-1] + left - right;
            }
        }
        return ops;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
