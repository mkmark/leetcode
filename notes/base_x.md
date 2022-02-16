# base x

```cpp
int x = i;
// position, from right (0) to left
int p = 0;
while(n!=0){
    // value at position p
    int m = x%3;
    // do sth with p++ and m
    // in binary case x >>= 1;
    x /= 3;
}
```

```cpp
int int_pow(int x, int p) {
    int res = 1;
    for (int i=1; i<=p; ++i){
        res *= x;
    }
    return res;
}
```