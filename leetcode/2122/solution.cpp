/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 53 ms, faster than 90.49% of C++ online submissions for Recover the Original Array.
Memory Usage: 28.3 MB, less than 76.34% of C++ online submissions for Recover the Original Array.
*/

#include <vector>       // std::vector
#include <algorithm>    // std::sort

class Solution {
public:
    std::vector<int> recoverArray(std::vector<int>& nums) {
        std::sort (nums.begin(), nums.end());
        int nums_size = nums.size();
        int original_size = nums_size/2;

        // iterate m to get next possible k
        for (int m = 1; m<nums_size; ++m){
            int kx2 = nums[m] - nums[0];
            if (kx2%2){
                continue;
            }
            if (kx2 == 0){
                continue;
            }
            int k = kx2/2;
            std::vector<bool> is_higher(nums_size);
            std::vector<int> original(original_size);

            int last_j = 0;
            int count = 0;
            // iterate i to check if nums[i] + k*2 exist in range
            for (int i = 0; i<nums_size-1; ++i){
                if (is_higher[i]){
                    continue;
                }else{
                    int target = nums[i] + kx2;
                    auto lower = std::lower_bound(nums.begin()+std::max(i+1,last_j+1), nums.end()-1, target);
                    const bool found = lower != nums.end() && *lower == target;
                    int j = lower - nums.begin();
                    if (found){
                        // next i
                        is_higher[j] = true;
                        last_j = j;
                        original[count++] = nums[i]+k;
                    }
                    else {
                        // next m
                        break;
                    }
                }
                if (count == original_size){
                    return original;
                }
            }
        }
        std::vector<int> tmp;
        return tmp;
    }
};
