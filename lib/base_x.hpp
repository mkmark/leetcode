/*
author: mark@mkmark.net
*/

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
int get_ith(int i, int dec, int base){
    return (dec / int_pow(base, i)) % base;
}

/**
 * @brief add the ith single mask
 * 
 * @param i position
 * @param dec decimal mask
 * @param base 
 * @param to_add single mask to add
 * @return int 
 */
int add_ith(int i, int dec, int base, int to_add){
    return dec + to_add * int_pow(base, i);
}

/**
 * @brief set the ith single mask
 * 
 * @param i position
 * @param dec decimal mask
 * @param base 
 * @param to_set single mask to set
 * @return int 
 */
int set_ith(int i, int dec, int base, int to_set){
    return add_ith(i, dec, base, to_set-get_ith(i, dec, base));
}
