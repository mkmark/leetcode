/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 446 ms, faster than 78.08% of C++ online submissions for Minimum Difference in Sums After Removal of Elements.
Memory Usage: 142 MB, less than 55.13% of C++ online submissions for Minimum Difference in Sums After Removal of Elements.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <queue>        // std::priority_queue

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        // initialize pq1 as left 1/3, pq2 as right 1/3
        int n = nums.size()/3;
        vector<int> v1_initial(nums.begin(), nums.begin()+n);
        vector<int> v2_initial(nums.begin()+2*n, nums.begin()+3*n);
        long long v1_initial_sum = sum_vec(v1_initial);
        long long v2_initial_sum = sum_vec(v2_initial);
        priority_queue<int> pq1_initial(v1_initial.begin(), v1_initial.end());
        priority_queue<int, vector<int>, greater<int>> pq2_initial(v2_initial.begin(), v2_initial.end());
        // to store sum
        vector<long long> sum1s(n+1);
        vector<long long> sum2s(n+1);
        // iter through i to add middle member to pq1 and pq2, while poping out extreme member btw
        auto pq1_i = pq1_initial;
        auto pq2_i = pq2_initial;
        sum1s[0] = v1_initial_sum;
        sum2s[0] = v2_initial_sum;
        for (int i=1;i<n+1;++i){
            pq1_i.push(nums[n+i-1]);
            pq2_i.push(nums[2*n-i]);
            // add middle member
            sum1s[i] = sum1s[i-1] + nums[n+i-1];
            sum2s[i] = sum2s[i-1] + nums[2*n-i];
            // pop extreme member
            sum1s[i] -= pq1_i.top();
            sum2s[i] -= pq2_i.top();
            pq1_i.pop();
            pq2_i.pop();
        }
        // result calculated as sum1s[i] - sum2s[n-i]
        long long res = sum1s[0] - sum2s[0];
        for (int i=0;i<n+1;++i){
            res = min(
                res,
                sum1s[i] - sum2s[n-i]
            );
        }
        return res;
    }
    
    inline long long sum_vec(vector<int> arr){
        long long sum = 0;
        for (int i : arr){
            sum += i;
        }
        return sum;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
