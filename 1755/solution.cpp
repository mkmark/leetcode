#include <vector>       // std::vector
#include <iostream>     // std::iostream
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        // split into 2 piles
        int nums_1_size = n/2;
        int nums_2_size = n-nums_1_size;
        vector<int> nums_1(nums.begin(), nums.begin()+nums_1_size);
        vector<int> nums_2(nums.begin()+nums_1_size, nums.end());

        // sum each pile
        unordered_set<int> nums_1_sum_set;
        unordered_set<int> nums_2_sum_set;
        int stop = 0;
        if(dfs_all_sub_sum(nums_1, nums_1_sum_set, 0, 0, goal, stop) == 0){
            return 0;
        }
        if(dfs_all_sub_sum(nums_2, nums_2_sum_set, 0, 0, goal, stop) == 0){
            return 0;
        }

        // for pile 1 find minimal diff in pile 2
        vector<int> nums_2_sum_vec(nums_2_sum_set.begin(), nums_2_sum_set.end());
        sort(nums_2_sum_vec.begin(), nums_2_sum_vec.end());
        int res = abs(goal);
        for (auto i : nums_1_sum_set){
            int target = goal-i;
            int l = lower_bound(nums_2_sum_vec.begin(), nums_2_sum_vec.end(), target) - nums_2_sum_vec.begin();
            if (l == 0){
                res = min(res, abs(nums_2_sum_vec[0]-target));
            }
            else if (l == nums_2_sum_vec.size()){
                res = min(res, abs(nums_2_sum_vec[l-1]-target));
            } else {
                res = min(res, abs(nums_2_sum_vec[l-1]-target));
                res = min(res, abs(nums_2_sum_vec[l]-target));
            }
            if (res==0){return 0;}
        }
        return res;
    }

    void dfs_all_sub_sum(vector<int>& arr, unordered_set<int>& set, int sum, int i){
        if (i>=arr.size()){
            return;
        }
        set.insert(sum);
        dfs_all_sub_sum(arr, set, sum, i+1);
        sum+=arr[i];
        set.insert(sum);
        dfs_all_sub_sum(arr, set, sum, i+1);
    }

    /**
     * @brief While all answers depend on the 'two half solution' to stay within the time limit, test case 72 poses an unnecessarily strict time limit, which in turn, can be exploited and circumvented if we 'luckily' bump into the correct case during the initial split up. Suppose we split the array in an 'unlucky' way that each part does not have the subarray to meet the goal, the algorithm will still have the same time complexity but will fail just because we are not lucky enough.
     * 
     * @param arr 
     * @param set 
     * @param sum 
     * @param i current index
     * @param goal
     * @param stop indicate if we should stop
     * @return int 0 indicates we should return 0 immediately as we have luckily bumped into a subset that meets the goal
     */
    int dfs_all_sub_sum(vector<int>& arr, unordered_set<int>& set, int sum, int i, int goal, int& stop){
        if (stop){
            return 0;
        }
        if (i>=arr.size()){
            return 1;
        }
        if (sum == goal){
            stop = 1;
            return 0;
        }
        set.insert(sum);
        dfs_all_sub_sum(arr, set, sum, i+1, goal, stop);
        sum+=arr[i];
        if (sum == goal){
            stop = 1;
            return 0;
        }
        set.insert(sum);
        dfs_all_sub_sum(arr, set, sum, i+1, goal, stop);
        return 1;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
