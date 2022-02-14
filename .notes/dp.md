# dynamic programming

## scene

use when a situation is determined only by its neighbour, i.e. recursion.

```cpp
// dynamic programming storage
// dimension determined by number of condition required to make the situation unique
int dp[]...
// deep first search
int dfs(int& dp, int i, ...){
    // boundry condition
    if ...
    // cached
    if dp[i]...
    // recursive calc and cache
    else
        return dp[i] = dfs(dp, ...)
}
```