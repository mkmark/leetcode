/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <queue>        // std::priority_queue

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<int> v1_initial(nums.begin(), nums.begin()+n);
        vector<int> v2_initial(nums.begin()+2*n, nums.begin()+3*n);
        int v1_initial_sum = sum_vec(v1_initial);
        int v2_initial_sum = sum_vec(v2_initial);
        priority_queue<int> pq1_initial(v1_initial.begin(), v1_initial.end());
        priority_queue<int, vector<int>, greater<int>> pq2_initial(v2_initial.begin(), v2_initial.end());
        
        vector<priority_queue<int>> pq1s(n+1);
        vector<priority_queue<int, vector<int>, greater<int>>> pq2s(n+1);
        vector<int> sum1s(n+1);
        vector<int> sum2s(n+1);

        pq1s[0] = pq1_initial;
        pq2s[0] = pq2_initial;
        sum1s[0] = v1_initial_sum;
        sum2s[0] = v2_initial_sum;
        for (int i=1;i<n+1;++i){
            auto pq1_i = pq1s[i-1];
            auto pq2_i = pq2s[i-1];
            pq1_i.push(nums[n+i-1]);
            pq2_i.push(nums[2*n-i]);
            pq1s[i] = pq1_i;
            pq2s[i] = pq2_i;
            sum1s[i] = sum1s[i-1] + nums[n+i-1];
            sum2s[i] = sum2s[i-1] + nums[2*n-i];
        }

        for (int i=1;i<n+1;++i){
            for (int j=0;j<i;++j){
                sum1s[i] -= pq1s[i].top();
                sum2s[i] -= pq2s[i].top();
                pq1s[i].pop();
                pq2s[i].pop();
            }
        }

        int res = sum1s[0] - sum2s[0];
        for (int i=0;i<n+1;++i){
            res = min(
                res,
                sum1s[i] - sum2s[n-i]
            );
        }
        return res;
    }
    inline long long sum_vec(vector<int> arr){
        int sum = 0;
        for (int i : arr){
            sum += i;
        }
        return sum;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
