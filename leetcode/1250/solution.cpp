/*
author: mark@mkmark.net
time: O(nloglogm)
space: O(loglogm)

Runtime: 39 ms, faster than 99.09% of C++ online submissions for Check If It Is a Good Array.
Memory Usage: 30.1 MB, less than 6.38% of C++ online submissions for Check If It Is a Good Array.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int nums_length = size(nums);

        list factors = get_factors(nums[0]);

        for (int i=1; i<nums_length; ++i){
            if (factors.empty()){
                break;
            }
            factors.remove_if(
                [&nums, &i](auto factor){
                    return (nums[i] % factor);
                }
            );
        }

        return factors.empty();
    }

    list<int> get_factors(int n) {
        list<int> factors;
        if (n%2 == 0) {
            factors.push_back(2);
            while (n%2 == 0){
                n /= 2;
            }
        }
        for (int i = 3; i <= n; i += 2){
            if (n%i == 0) {
                factors.push_back(i);
            }
            while (n%i == 0){
                n /= i;
            }
        }
        return factors;
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
