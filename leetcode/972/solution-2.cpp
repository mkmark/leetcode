/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Equal Rational Numbers.
Memory Usage: 5.9 MB, less than 88.10% of C++ online submissions for Equal Rational Numbers.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    bool isRationalEqual(string s, string t) {
        expand(s);
        expand(t);
        return abs(stod(s) - stod(t)) < 1e-11;
    }

    void expand(string &s){
        int s_size = size(s);
        int i = s_size-1;
        if (s[i] == ')'){
            while (s[--i] != '(');
            string loop = s.substr(i+1, s_size-i-2);
            s.resize(i);
            while (size(s)<20){
                s += loop;
            }
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
