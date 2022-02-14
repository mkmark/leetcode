# sort

## sort index
```cpp
#include <algorithm>    // std::sort
#include <numeric>      // std::iota
vector<int> idx(n);
iota(idx.begin(), idx.end(), 0);
sort(idx.begin(), idx.end(), [&](int i,int j){return arr[i]<arr[j];});
```

## remember to use ref
```cpp
vector<vector<int>> mat;
sort(mat.begin(), mat.end(), [&](vector<int>& i,vector<int>& j){return i[1]<j[1];});
```