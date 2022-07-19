/*
author: mark@mkmark.net
reference: https://www.geeksforgeeks.org/kasais-algorithm-for-construction-of-lcp-array-from-suffix-array/
*/

#include <bits/stdc++.h>

/**
 * @brief LCP using kaisa
 * 
 */
class LCP {
public:
    using size_type = unsigned;
    using pointer = size_type*;
    using const_pointer = const size_type*;
    
    // size_type max_lcp = 0;
    // size_type max_lcp_pos = 0;
    pointer lcp;

private:
    std::unique_ptr<size_type[]> data;

public:
    LCP(const std::string& s, size_type n, pointer sa)
        : data(std::make_unique<size_type[]>(n))
        , lcp(data.get())
    {
        kaisa(s, n, sa);
    }

private:
    size_type max_lcp;
    /**
     * @brief kaisa algorithm to get longest common prefix, aka. LCP
     * 
     * @tparam S 
     * @param s 
     * @param n 
     * @param sa 
     */
    template <typename S>
    void kaisa(
        const S& s,
        size_type n,
        pointer sa
    ){
        // An auxiliary array to store inverse of suffix array
        // elements. For example if suffixArr[0] is 5, the
        // rev_index[5] would store 0.  This is used to get next
        // suffix string from suffix array.
        size_type sa_idx[n];
        for (size_type i = 0; i < n; i++){
            sa_idx[sa[i]] = i;
        }
    
        // Initialize length of previous LCP
        size_type k = 0;
    
        // Process all suffixes one by one starting from
        // first suffix in txt[]
        for (size_type i = 0; i<n; ++i){
            /* If the current suffix is at n-1, then we don’t
            have next substring to consider. So lcp is not
            defined for this substring, we put zero. */
            if (sa_idx[i] == n-1){
                k = 0;
                continue;
            }
    
            /* j contains index of the next substring to
            be considered  to compare with the present
            substring, i.e., next string in suffix array */
            size_type j = sa[sa_idx[i]+1];
    
            // Directly start matching from k'th index as
            // at-least k-1 characters will match
            if (k>0){
                --k;
            }
            while (i+k<n && j+k<n && s[i+k]==s[j+k]){
                k++;
            }

            lcp[i] = k;

            // if (k > max_lcp){
            //     max_lcp = k;
            //     max_lcp_pos = i;
            // }
        }
    }
};
