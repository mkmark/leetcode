/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 324 ms, faster than 100.00% of C++ online submissions for Design Bitset.
Memory Usage: 203.2 MB, less than 10.32% of C++ online submissions for Design Bitset.
*/

#include <bits/stdc++.h>
using namespace std;

class Bitset {
public:
    bool bits[100000] = {};
    int size;
    int cnt=0;
    bool is_flipped=false;

    Bitset(int size):size(size) {}
    
    void fix(int idx) {
        if (bits[idx]^is_flipped){}
        else{
            bits[idx] = !is_flipped;
            ++cnt;
        }
    }
    
    void unfix(int idx) {
        if (bits[idx]^is_flipped){
            bits[idx] = is_flipped;
            --cnt;
        }
    }
    
    void flip() {
        is_flipped = !is_flipped;
        cnt = size-cnt;
    }
    
    bool all() {
        return cnt==size;
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string s;
        for (int i=0; i<size; ++i){
            if (bits[i]^is_flipped){
                s.push_back('1');
            } else {
                s.push_back('0');
            }
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
