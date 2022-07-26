/*
author: mark@mkmark.net
time: O(n2)
space: O(n)

Runtime: 488 ms, faster than 100.00% of C++ online submissions for Car Fleet II.
Memory Usage: 129.9 MB, less than 25.36% of C++ online submissions for Car Fleet II.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        /// car = { b, k }
        int n = size(cars);

        vector<double> res(n);
        /// envelop k and b
        int k[100000];
        double b[100000];
        /// collision position of car ? and car i
        double x[100000];

        int env_size = 1;
        res[n-1] = -1;
        k[0] = cars[n-1][1];
        b[0] = cars[n-1][0];

        int j;
        int k_i;
        double b_i;
        for (int i=n-2; i>-1; --i){
            k_i = cars[i][1];
            b_i = cars[i][0];
            for (j = 0; j<env_size; ++j){
                /// will never caught
                if (k_i <= k[j]) break;
                /// y = k1 x + b1
                /// y = k2 x + b2
                /// x = (b2 - b1)/(k1 - k2)
                x[j] = (b[j] - b_i) / (k_i - k[j]);
            }
            if (j) {
                /// use env_size to temp store the min element pos
                env_size = min_element(x, x+j) - x;
                res[i] = x[env_size];
                /// the actual replacement happens after min element
                ++env_size;
            } else {
                env_size = 0;
                res[i] = -1;
            }
            k[env_size] = k_i;
            b[env_size] = b_i;
            /// the actual env_size
            ++env_size;
        }

        return res;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
