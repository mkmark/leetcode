/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 1948 ms, faster than 5.08% of C++ online submissions for Longest Duplicate Substring.
Memory Usage: 231.9 MB, less than 49.04% of C++ online submissions for Longest Duplicate Substring.
*/

// multiset to avoid hash collision

#include <bits/stdc++.h>

using namespace std;

/*
author: mark@mkmark.net
*/

#include <queue>
#include <string>

class RabinKarpQueue{
private:
    std::queue<char> que;
    long long base_power_mod = 1;

public:
    int base = 26;
    int prime = 10007;
    long long hash = 0;
    int size() {return que.size();};
    char front() {return que.front();};

    void initial_push(char c){
        base_power_mod = base_power_mod * base % prime;
        push(c);
    }

    void push(char c){
        hash = (hash*base + val(c)) % prime;
        que.push(c);
    }

    void pop(){
        hash = (hash - val(que.front()) * base_power_mod) % prime;
        hash = hash < 0 ? (hash+prime) : hash;
        que.pop();
    }

    inline int val(char& c){
        return c-'a';
    }

    int base_power(int power){
        long long res;
        for (int i = 0; i < power; ++i){
            res *= base;
            res %= prime;
        }
        return res;
    }

    void init(std::string s){
        int n = s.length();
        for (int i = 0; i<s.length(); ++i){
            initial_push(s[i]);
        }
    }

    RabinKarpQueue(){};

    RabinKarpQueue(std::string s){
        init(s);
    };

    RabinKarpQueue(std::string s, int base)
        : base(base)
    {
        init(s);
    };

    RabinKarpQueue(std::string s, int prime, int base)
        : base(base)
        , prime(prime)
    {
        init(s);
    };
};

class Solution {
public:
    string longestDupSubstring(const string& s)
    {
        int l = 0;
        int r = s.size();
        int m;
        int pos = 0;
        int length = 0;
        int dup_pos;
        while (l<=r){
            m = (l+r)/2;
            dup_pos = has_dup(s, m);
            if (dup_pos){
                l = m + 1;
                pos = dup_pos;
                length = m;
            } else {
                r = m - 1;
            }
        }
        return s.substr(pos, length);
    }

    /**
     * @brief 
     * 
     * @param s 
     * @param l 
     * @param r 
     * @return int duplication start index
     */
    int has_dup(const string& s, int sz){
        const int n = s.size();
        multimap<int,int> mp;
        RabinKarpQueue rks(s.substr(0,sz));
        mp.insert(make_pair(rks.hash, 0));
        for (int i = 1; i < n-sz+1; ++i){
            rks.push(s[i+sz-1]);
            rks.pop();
            auto its = mp.equal_range(rks.hash);
            for (auto it = its.first; it != its.second; ++it){
                if (is_dup(s, it->second, i, sz)){
                    return i;
                }
            }
            mp.insert(make_pair(rks.hash, i));

        }
        return 0;
    }

    bool is_dup(const string& s, int i, int j, int n){
        for (int k = 0; k < n; ++k){
            if (s[i] != s[j]){
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
};
