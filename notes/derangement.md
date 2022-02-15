# Derangement

https://en.wikipedia.org/wiki/Derangement

time: O(!n)

see [1879](../leetcode/1879/solution.cpp), [1947](../leetcode/1947/solution.cpp)

```cpp
/**
 * @brief used_j_mask indicates numbers that have been used in arr2, 
 * the count of used_j_mask (x) corresponds to the first x numbers that that been used in arr1,
 * so there's no need to mem used_i_mask
 * 
 * @param arr1 
 * @param arr2 
 * @param i arr1[i]
 * @param used_j_mask
 * @return int 
 */
int dfs(
    vector<int>& arr1, 
    vector<int>& arr2,
    int i,
    int used_j_mask
){
    int n = arr1.size();
    if (i>=n){
        return 0;
    }
    if (dp[used_j_mask] != INT32_MAX){
        return dp[used_j_mask];
    }
    int res = INT32_MAX;
    for (int j=0; j<n; ++j){
        // j used, skip
        if (used_j_mask & (1<<j)){
            continue;
        }
        res = min(
            res,
            // do sth with i, j
            (arr1[i]^arr2[j]) + dfs_min_xor_sum(
                arr1, 
                arr2, 
                i+1,
                used_j_mask | (1<<j)
            )
        );
    }
    return dp[used_j_mask] = res;
}
```