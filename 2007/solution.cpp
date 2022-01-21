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
            for (int j = std::max(last_j+1, i+1); j < changed_size; ++j){
                if (changed[j] == 2*changed[i]){
                    original[count] = changed[i];
                    count++;
                    last_j = j;
                    is_dbl[j] = true;
                    break;
                }
                if (j == changed_size-1){
                    //end reached but not found for one instance
                    std::vector<int> empty;
                    return empty;
                }
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