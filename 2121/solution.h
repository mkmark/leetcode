// Runtime: 445 ms, faster than 74.12% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.
// Memory Usage: 121.5 MB, less than 83.76% of C++ online submissions for Maximum Product of the Length of Two Palindromic Subsequences.

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <execution>

class Solution
{
public:
    std::vector<long long> getDistances(std::vector<int> &arr)
    {
        std::vector<long long> intervals(arr.size());
        std::unordered_map<int, std::vector<int>> indices_map;
        std::vector<int> indices_in_indices_map(arr.size());

        for (int i = 0; i < arr.size(); ++i)
        {
            std::vector<int> &current_indices_map = indices_map[arr[i]];
            indices_in_indices_map[i] = current_indices_map.size();
            current_indices_map.push_back(i);
        }

        for (int i = 0; i<arr.size(); ++i){
            long long sum = 0;
            std::vector<int>& indices = indices_map[arr[i]];
            int index_in_indices= indices_in_indices_map[i];
            if (index_in_indices > 0){
                int previous_index_in_indices = index_in_indices -1;
                int previous_i = indices[previous_index_in_indices];
                sum = intervals[previous_i];
                int delta = i - previous_i;
                sum += delta * (2 * index_in_indices - indices.size());
            } else {
                for (int j = index_in_indices; j<indices.size(); ++j){
                    sum += indices[j];
                }
                sum += i * (2 * index_in_indices - indices.size());
            }

            intervals[i]=(sum);
        }
        return intervals;
    }
};