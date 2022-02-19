/*
author: mark@mkmark.net
time: O(nlogn)
space: O()

Runtime: 1045 ms, faster than 68.12% of C++ online submissions for Longest Duplicate Substring.
Memory Usage: 13.2 MB, less than 92.75% of C++ online submissions for Longest Duplicate Substring.

reference: https://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/
*/

// suffix array, lcp

#include <bits/stdc++.h>
using namespace std;

class suffix_array{
    string s;
    // size
    int n;

    struct suffix{
        // original string index
        int idx; 
        // {this.rank, next.rank}
        int rank[2]; 
    };

    // A comparison function used by sort() to compare two suffixes
    // Compares two pairs, returns true if first pair is smaller
    static bool cmp(struct suffix& a, struct suffix& b){
        return (a.rank[0] == b.rank[0]) ? 
            (a.rank[1] < b.rank[1]) :
            (a.rank[0] < b.rank[0]);
    }

public: 
    vector<int> index;
    int max_lcp = 0;
    int max_lcp_i = 0;
    // This is the main function that takes a string s of size n as an
    // argument, builds and return the suffix array for the given string
    suffix_array(string& s):s(s)
    {
        n = s.size();
        // A structure to store suffixes and their indexes
        struct suffix suffixes[n];
    
        // Store suffixes and their indexes in an array of structures.
        // The structure is needed to sort the suffixes alphabetically
        // and maintain their old indexes while sorting
        for (int i = 0; i < n; i++){
            suffixes[i].idx = i;
            suffixes[i].rank[0] = s[i] - 'a';
            suffixes[i].rank[1] = ((i+1) < n) ? (s[i + 1] - 'a') : -1;
        }
    
        // Sort the suffixes using the comparison function
        // defined above.
        sort(suffixes, suffixes+n, cmp);
    
        // At this point, all suffixes are sorted according to first
        // 2 characters.  Let us sort suffixes according to first 4
        // characters, then first 8 and so on

        // This array is needed to get the index in suffixes[]
        // from original index.  This mapping is needed to get
        // next suffix.
        int ind[n];  
        for (int k=4; k<2*n; k*=2){
            // Assigning rank and index values to first suffix
            int rank = 0;
            int prev_rank = suffixes[0].rank[0];
            suffixes[0].rank[0] = rank;
            ind[suffixes[0].idx] = 0;
    
            // Assigning rank to suffixes
            for (int i = 1; i < n; i++){
                // If first rank and next ranks are same as that of previous
                // suffix in array, assign the same new rank to this suffix
                if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1]
                ){
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = rank;
                } else {// Otherwise increment rank and assign
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = ++rank;
                }
                ind[suffixes[i].idx] = i;
            }
    
            // Assign next rank to every suffix
            for (int i = 0; i < n; i++){
                int next_idx = suffixes[i].idx + k/2;
                suffixes[i].rank[1] = (next_idx < n) ? suffixes[ind[next_idx]].rank[0] : -1;
            }
    
            // Sort the suffixes according to first k characters
            sort(suffixes, suffixes+n, cmp);
        }
    
        // Store indexes of all sorted suffixes in the suffix array
        vector<int> res(n);
        for (int i = 0; i < n; i++){
            res[i] = suffixes[i].idx;
        }
    
        // Return the suffix array
        index = res;
    }

    /* To construct and return LCP */
    vector<int> max_lcp_str_idx()
    {
        // An auxiliary array to store inverse of suffix array
        // elements. For example if suffixArr[0] is 5, the
        // rev_index[5] would store 0.  This is used to get next
        // suffix string from suffix array.
        vector<int> rev_index(n, 0);
        for (int i=0; i < n; i++){
            rev_index[index[i]] = i;
        }
    
        // Initialize length of previous LCP
        int k = 0;
    
        // Process all suffixes one by one starting from
        // first suffix in txt[]
        for (int i=0; i<n; ++i){
            /* If the current suffix is at n-1, then we don’t
            have next substring to consider. So lcp is not
            defined for this substring, we put zero. */
            if (rev_index[i] == n-1){
                k = 0;
                continue;
            }
    
            /* j contains index of the next substring to
            be considered  to compare with the present
            substring, i.e., next string in suffix array */
            int j = index[rev_index[i]+1];
    
            // Directly start matching from k'th index as
            // at-least k-1 characters will match
            if (k>0){
                --k;
            }
            while (i+k<n && j+k<n && s[i+k]==s[j+k]){
                k++;
            }

            if (k>max_lcp){
                max_lcp = k;
                max_lcp_i = i;
            }

            max_lcp = max(max_lcp, k);
        }
    
        // return the constructed lcp array
        vector<int> res = {max_lcp_i, max_lcp};
        return res;
    }
};


class Solution {
public:
    string longestDupSubstring(string& s) {
        suffix_array sa(s);
        auto res = sa.max_lcp_str_idx();
        return s.substr(res[0], res[1]);
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
