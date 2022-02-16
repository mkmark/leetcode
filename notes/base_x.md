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
/**
 * @brief integer power
 * 
 * @param x base
 * @param p power
 * @return int 
 */
int int_pow(int x, int p) {
    int res = 1;
    for (int i=1; i<=p; ++i){
        res *= x;
    }
    return res;
}

/**
 * @brief get the ith single mask
 * 
 * @param i position
 * @param dec decimal mask
 * @param base 
 * @return int 
 */
inline int get_ith(int i, int dec, int base){
    dec /= int_pow(base, i);
    return dec % base;
}

/**
 * @brief add the ith single mask
 * 
 * @param i position
 * @param dec decimal mask
 * @param base 
 * @param new single mask to set
 * @param ori original single mask
 * @return int 
 */
inline int add_ith(int i, int dec, int base, int to_add){
    return dec + to_add * int_pow(base, i);
}
```