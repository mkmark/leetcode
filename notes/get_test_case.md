# get test case

get specific test case, e.g. 42

```cpp
int cnt;
class Solution {
public:
    ... Solution(){
        if (++cnt == 42) assert(0);
        /// correct solution
    }
}
```

or deliberate tle to get a complex test case, e.g. sleep 0.5s

```cpp
this_thread::sleep_for(chrono::nanoseconds(5e8));
/// correct solution
```
