/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 244 ms, faster than 96.35% of C++ online submissions for Find Original Array From Doubled Array.
Memory Usage: 116.8 MB, less than 97.83% of C++ online submissions for Find Original Array From Doubled Array.
*/

#include <vector>       // std::vector
#include <algorithm>    // std::sort

class Solution {
public:
    std::vector<int> findOriginalArray(std::vector<int>& changed) {
        int changed_size = changed.size();
        if (changed_size%2){
            std::vector<int> empty;
            return empty;
        }
        std::vector<int> original(changed_size/2);
        std::sort (changed.begin(), changed.end());
        std::vector<bool> is_dbl(changed_size);
        int count = 0;
        int last_j = 0;
        for (int i = 0; i < changed_size-1; ++i){
            if (is_dbl[i]){
                continue;
            }
            int target = 2*changed[i];
            auto lower = std::lower_bound(changed.begin() + std::max(i+1,last_j+1), changed.end()-1, target);
            int j = lower - changed.begin();
            const bool found = lower != changed.end() && *lower == target;
            if (found){
                last_j = j;
                is_dbl[j] = true;
                original[count++] = changed[i];
            }else{
                std::vector<int> empty;
                return empty;
            }
        }
        if (count == changed_size/2){
            return original;
        } else {
            std::vector<int> empty;
            return empty;
        }
    }
};