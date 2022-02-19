/*
author: mark@mkmark.net
time: O(N)
space: O(1)

Runtime: 12 ms, faster than 99.94% of C++ online submissions for Find Substring With Given Hash Value.
Memory Usage: 10.5 MB, less than 41.80% of C++ online submissions for Find Substring With Given Hash Value.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int target) {
        int n = s.length();
        // calc power^k
        long long power_k = 1;
        for (int i=0; i<k; ++i){
            power_k *= power;
            power_k %= modulo;
        }
        // calc init hash
        int hash = 0;
        for (int i=n-1; i>n-k-1; --i){
            hash = hash_push(hash, s[i], power, modulo);
        }
        int res_i;
        if (hash==target){
            res_i = n-k;
        }
        // slide
        for (int i=n-k; i>0; --i){
            hash = hash_push(hash, s[i-1], power, modulo);
            hash = hash_pop(hash, s[i-1+k], power, modulo, power_k);
            if (hash==target){
                res_i = i-1;
            }
        }
        return s.substr(res_i, k);
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
