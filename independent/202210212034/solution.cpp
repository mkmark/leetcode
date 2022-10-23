/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    int solution(vi a) {
        int n = size(a);
        queue<pair<int,int>> x;
        stack<pair<int,int>> y;
        int min = a[0];
        int max = a[n-1];
        x.emplace(min, 0);
        y.emplace(max, n-1);
        for (int i=1; i<n; ++i){
            if (a[i]<min){
                min = a[i];
                x.emplace(min, i);
            }
        }
        for (int i=n-1; i>0; --i){
            if (a[i]>max){
                max = a[i];
                x.emplace(max, i);
            }
        }
        int ans = -2147483648;
        while (!x.empty() && !y.empty()){
            if (x.front().first > y.top().first){
                x.pop();
            } else {
                ans = std::max(ans, y.top().second - x.front().second);
                y.pop();
            }
        }
        return ans;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
