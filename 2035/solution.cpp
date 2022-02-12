#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        // split into 2 piles
        vector<int> nums_1(nums.begin(), nums.begin()+n);
        vector<int> nums_2(nums.begin()+n, nums.end());
        // sum each pile
        vector<unordered_set<int>> nums_1_sum_sets(n+1);
        nums_1_sum_sets[0].insert(0);
        vector<unordered_set<int>> nums_2_sum_sets(n+1);
        nums_1_sum_sets[0].insert(0);
        dfs_all_sub_sum(nums_1, nums_1_sum_sets, 0, 0, 0);
        dfs_all_sub_sum(nums_2, nums_2_sum_sets, 0, 0, 0);

        int sum = *nums_1_sum_sets[n].begin() + *nums_2_sum_sets[n].begin();
        int goal = (sum)/2;

        int res = abs(*nums_1_sum_sets[n].begin() - *nums_2_sum_sets[n].begin());
        // for sum in nums_1_sum_sets[i], with goal find minimal diff in nums_2_sum_sets[n-i]
        for (int i=0; i<n; ++i){
            vector<int> nums_2_sum_vec(nums_2_sum_sets[n-i].begin(), nums_2_sum_sets[n-i].end());
            sort(nums_2_sum_vec.begin(), nums_2_sum_vec.end());
            for (auto i : nums_1_sum_sets[i]){
                int target = goal-i;
                int l = lower_bound(nums_2_sum_vec.begin(), nums_2_sum_vec.end(), target) - nums_2_sum_vec.begin();
                if (l == 0){
                    res = min(res, abs(2*i+2*nums_2_sum_vec[0]-sum));
                }
                else if (l == nums_2_sum_vec.size()){
                    res = min(res, abs(2*i+2*nums_2_sum_vec[l-1]-sum));
                } else {
                    res = min(res, abs(2*i+2*nums_2_sum_vec[l-1]-sum));
                    res = min(res, abs(2*i+2*nums_2_sum_vec[l]-sum));
                }
                if (res==0){return 0;}
            }
        }
        return res;
    }

    void dfs_all_sub_sum(vector<int>& arr, vector<unordered_set<int>>& sets, int sum, int i, int count){
        if (i>=arr.size()){
            return;
        }
        dfs_all_sub_sum(arr, sets, sum, i+1, count);
        sum+=arr[i];
        ++count;
        sets[count].insert(sum);
        dfs_all_sub_sum(arr, sets, sum, i+1, count);
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
