#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include <tuple>        // tuple
#include <tgmath.h>     // pow

class Solution {
public:
    // suppose an array is mixed by 2 array with one on a constant diff of the other, find the smaller one and the diff
    inline std::tuple<std::vector<int>, int> find_smaller_half_array_and_diff(std::vector<int>& sorted_arr){
        int arr_size = sorted_arr.size();
        int half_arr_size = arr_size/2;

        for (int i_high = 1; i_high<arr_size; ++i_high){
            int diff = sorted_arr[i_high] - sorted_arr[0];
            // store if the matching index is the higher one in sorted_arr
            std::vector<bool> is_higher(arr_size);
            std::vector<int> smaller_half_arr(half_arr_size);

            int j_last = 0;
            int count = 0;
            // iterate i to check if target exist in range
            for (int i = 0; i<arr_size-1; ++i){
                if (is_higher[i]){
                    continue;
                }else{
                    int target = sorted_arr[i] + diff;
                    auto lower = std::lower_bound(sorted_arr.begin()+std::max(i+1,j_last+1), sorted_arr.end()-1, target);
                    const bool found = lower != sorted_arr.end() && *lower == target;
                    // j is the index of target
                    int j = lower - sorted_arr.begin();
                    if (found){
                        // next i
                        is_higher[j] = true;
                        j_last = j;
                        smaller_half_arr[count++] = sorted_arr[i];
                    }
                    else {
                        // next i_high
                        break;
                    }
                }
                if (count == half_arr_size){
                    return std::make_tuple(smaller_half_arr, diff);
                }
            }
        }
        throw std::invalid_argument("smaller_half_array not found");
    }

    std::vector<int> recoverArray(int n, std::vector<int>& sums) {
        std::sort (sums.begin(), sums.end());
        std::vector<int> possible_diffs(n);
        for (int i = 0; i<n; ++i){
            auto result = find_smaller_half_array_and_diff(sums);
            sums = std::get<0>(result);
            possible_diffs[i]=std::get<1>(result);
        }

        // find subarray with given sum
        int sum = 0;
        int target_lower = std::abs(sums[0]);
        int target_higher = std::abs(sums[sums.size()-1]);
        int target;
        bool is_computing_lower;
        if (target_lower<target_higher){
            target = target_lower;
            is_computing_lower = true;
        } else {
            target = target_higher;
            is_computing_lower = false;
        }
        // brutal
        for (int i = 0; i<pow(2,n); ++i){
            int sum = 0;
            std::vector<int> picked;
            for (int j = 0; j < n; ++j) {
                int i_bins_j = (i >> j) & 1;
                sum += i_bins_j * possible_diffs[j];
                if (i_bins_j) picked.push_back(j);
            }
            if (sum == target){
                for (int j :picked) {
                    possible_diffs[j] = -possible_diffs[j];
                }
                if (is_computing_lower){
                    for (int j = 0; j < n; ++j) {
                        possible_diffs[j] = -possible_diffs[j];
                    }
                }
                return possible_diffs;
            }
        }
        std::vector<int> empty;
        return empty;
    }
};