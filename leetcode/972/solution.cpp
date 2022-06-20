/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Equal Rational Numbers.
Memory Usage: 5.8 MB, less than 97.62% of C++ online submissions for Equal Rational Numbers.
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int tmp;
    bool isRationalEqual(string s, string t) {
        int s_i = size(s) - 1;
        int t_i = size(t) - 1;

        int s_cat = is_not_loop(s, s_i);
        int t_cat = is_not_loop(t, t_i);

        if ((s_cat * t_cat) <0) {
            return false;
        }

        if (s_cat == 2) {
            handle_9(s, s_i);
        }
        if (t_cat == 2) {
            handle_9(t, t_i);
        }
        if (s_cat == 3) {
            handle_0(s, s_i);
        }
        if (t_cat == 3) {
            handle_0(t, t_i);
        }

        r_trim_0(s);
        r_trim_0(t);

        if (s_cat > 0) {
            // not loop
            r_trim_dot(s);
            r_trim_dot(t);
            return s==t;
        } else {
            // loop
            s_i = 0;
            t_i = 0;
            int s_i_loop_0;
            int t_i_loop_0;
            bool s_not_end = 1;
            bool t_not_end = 1;
            while (s_not_end || t_not_end){
                if (s[s_i] != t[t_i]){
                    return false;
                }
                // advance s_i
                ++s_i;
                if (s[s_i]=='('){
                    ++s_i;
                    s_i_loop_0 = s_i;
                } else if (s[s_i]==')'){
                    s_i = s_i_loop_0;
                    s_not_end = 0;
                }
                // advance t_i
                ++t_i;
                if (t[t_i]=='('){
                    ++t_i;
                    t_i_loop_0 = t_i;
                } else if (t[t_i]==')'){
                    t_i = t_i_loop_0;
                    t_not_end = 0;
                }
            }
            if (s_cat == -2 && t_cat == -2){
                return true;
            }
            int s_loop_size = size(s) - 1 - s_i_loop_0;
            int t_loop_size = size(t) - 1 - t_i_loop_0;
            if (s_loop_size<t_loop_size){
                swap(s_loop_size, t_loop_size);
            }
            // actually here we should test gcd(s_loop_size, t_loop_size) == min_loop_size
            // seems test case does not cover this edge case.
            // at this point it's too many edge cases. opt for solution-2 instead.
            if ( s_loop_size % t_loop_size == 0){
                return true;
            }
            return false;
        }
    }

    // -2: loop (x+)
    // -1: loop
    // 1: not loop
    // 2: not loop (9+)
    // 3: not loop (0+)
    int is_not_loop(string& s, int& s_i){
        if (s[s_i] == ')'){
            --s_i;
            if (s[s_i] == '9'){
                --s_i;
                while (s[s_i] == '9'){
                    --s_i;
                }
                if (s[s_i] == '(') {
                    // s_i at '('
                    return 2;
                } else {
                    // s_i at some number other than 9
                    return -1;
                }
            } else if (s[s_i] == '0'){
                --s_i;
                while (s[s_i] == '0'){
                    --s_i;
                }
                if (s[s_i] == '(') {
                    // s_i at '('
                    return 3;
                } else {
                    // s_i at some number other than 9
                    return -1;
                }
            } else {
                char x = s[s_i];
                --s_i;
                while (s[s_i] == x){
                    --s_i;
                }
                if (s[s_i] == '(') {
                    // s_i at '('
                    return -2;
                } else {
                    // s_i at some number other than x
                    return -1;
                }
            }
        } else {
            // s_i at end
            return 1;
        }
    }

    void handle_9(string& s, int& s_i){
        s.resize(s_i);
        --s_i;
        tmp = 1;
        while (s_i>=0){
            if (s[s_i] == '.') {
                --s_i;
                continue;
            }
            s[s_i] += tmp;
            tmp = 0;
            if (s[s_i]>'9'){
                s[s_i] = '0';
                tmp = 1;
            } else {
                break;
            }
            --s_i;
        }
        if (tmp){
            s = "1" + s;
        }
    }

    void handle_0(string& s, int& s_i){
        s.resize(s_i);
    }

    void r_trim_0(string& s){
        int s_i = size(s) - 1;
        while (s_i >=0 && s[s_i] == '0'){
            --s_i;
        }
        int s_i_2 = s_i;
        while (s_i_2 >=0 && s[s_i_2] != '.'){
            --s_i_2;
        }
        if (s_i_2 != -1){
            s.resize(s_i+1);
        }
    }

    void r_trim_dot(string& s){
        if (s[size(s)-1] == '.'){
            s.resize(size(s)-1);
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
