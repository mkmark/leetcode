/*
author: mark@mkmark.net
time: O(n^3)
space: O()

Runtime: 6 ms, faster than 99.63% of C++ online submissions for Minimum XOR Sum of Two Arrays.
Memory Usage: 9.4 MB, less than 89.30% of C++ online submissions for Minimum XOR Sum of Two Arrays.
*/

// hungarian

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    #include "hungarian.hpp"

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vvi cost (n, vi(n));
        rep(i,0,n){
            rep(j,0,n){
                cost[i][j] = nums1[i] ^ nums2[j];
            }
        }
        return hungarian(cost).first;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
