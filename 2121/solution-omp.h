/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 
Memory Usage: 
*/

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

        #pragma omp parallel
        {
            #pragma omp single
            {
                for (auto it = indices_map.begin(); it != indices_map.end(); ++it)
                #pragma omp task
                {
                    auto indices = it->second;
                    for (int j = 0; j < indices.size(); ++j)
                    {
                        long long sum = 0;
                        int i = indices[j];
                        if (j == 0)
                        {
                            for (int k = 0; k < indices.size(); ++k)
                            {
                                sum += indices[k];
                            }
                            sum += i * (2 * j - indices.size());
                            intervals[i] = sum;
                            continue;
                        }
                        int previous_i = indices[j - 1];
                        sum = intervals[previous_i];
                        int delta = i - previous_i;
                        sum += delta * (2 * j - indices.size());
                        intervals[i] = sum;
                    }
                }
            }
        }
        return intervals;
    }
};