/*
author: mark@mkmark.net
time: O(N)
space: O(N)

Runtime: 16 ms, faster than 99.43% of C++ online submissions for Find Substring With Given Hash Value.
Memory Usage: 11.2 MB, less than 34.82% of C++ online submissions for Find Substring With Given Hash Value.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int target) {
        int n = s.length();
        string rs = s;
        reverse(rs.begin(), rs.end());
        // calc power^k
        long long power_k = 1;
        for (int i=0; i<k; ++i){
            power_k *= power;
            power_k %= modulo;
        }
        // calc init hash
        int hash = 0;
        for (int i=0; i<k; ++i){
            hash = hash_push(hash, rs[i], power, modulo);
        }
        int res_i;
        if (hash==target){
            res_i = 0;
        }
        // slide
        for (int i=0; i<n-k; ++i){
            hash = hash_push(hash, rs[i+k], power, modulo);
            hash = hash_pop(hash, rs[i], power, modulo, power_k);
            if (hash==target){
                res_i = i+1;
            }
        }
        return s.substr(n-res_i-k, k);
    }

    inline int val(char c){
        return c-96;
    }

    int hash_push(long long hash, char& c, int& power, int& modulo){
        return (hash*power + val(c)) % modulo;
    }

    int hash_pop(long long hash, char& c, int& power, int& modulo, long long& power_k){
        hash = (hash - val(c) * power_k) % modulo;
        return  hash<0 ? hash+modulo : hash;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
