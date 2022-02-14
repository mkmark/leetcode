/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 4 ms, faster than 99.88% of C++ online submissions for Maximum Good People Based on Statements.
Memory Usage: 8.7 MB, less than 22.25% of C++ online submissions for Maximum Good People Based on Statements.
*/

#include <vector>       // std::vector
#include <iostream>     // std::iostream

using namespace std;

class Solution {
public:
    const int BAD = 0;
    const int GOOD = 1;
    const int UNKNOWN = 2;

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();

        // initialize masks, each int is a bin mask
        vector<int> claim_good(n, 0);
        vector<int> claim_bad(n, 0);
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (statements[i][j] == GOOD){
                    claim_good[i] |= (1<<j);
                } else if (statements[i][j] == BAD){
                    claim_bad[i] |= (1<<j);
                }
            }
        }

        vector<int> complete_claim_good = claim_good;
        vector<int> complete_claim_bad = claim_bad;
        // complete each claim, such that it includes all the claims chain that can be deducted, and cache the result
        for (int i=0; i<n; ++i){
            vector<int> is_seen(n, 0);
            complete_claim_good[i] |= 1<<i;
            is_seen[i] |= 1<<i;
            dfs_complete(i, i, is_seen, complete_claim_good, complete_claim_bad);
        }

        // if i's complete claim contradicts, i is bad
        vector<int> is_bad(n, 0);
        for (int i=0; i<n; ++i){
            if (complete_claim_good[i] & complete_claim_bad[i]){
                is_bad[i] = 1;
            }
        }

        return dfs_max_good_after(
            0,
            is_bad,
            complete_claim_good,
            complete_claim_bad,
            0,
            0
        );
    }

    /** 
     *  @brief complete the claim set for index i upon claims of j
     *  @param is_seen is_seen for current run
     */
    void dfs_complete(
        int i,
        int j,
        vector<int>& is_seen,
        vector<int>& complete_claim_good, 
        vector<int>& complete_claim_bad
    ){ 
        // while claim_good[i] is not in is_seen
        while ((complete_claim_good[i] | is_seen[i]) != is_seen[i]){
            is_seen[i] |= complete_claim_good[j];
            int n = is_seen.size();
            for (int k=0; k<n; ++k){
                if (1<<k & complete_claim_good[j]){
                    complete_claim_good[i] |= complete_claim_good[k];
                    complete_claim_bad[i] |= complete_claim_bad[k];
                    dfs_complete(i, j, is_seen, complete_claim_good, complete_claim_bad);
                }
            }
        }
        return;
    }

    /** 
     *  @return the max good count after i
     *  @param local_claim_good bin mask of current iter
     *  @param local_claim_bad bin mask of current iter
     */
    int dfs_max_good_after(
        int i,
        vector<int>& is_bad,
        vector<int>& complete_claim_good, 
        vector<int>& complete_claim_bad,
        int local_claim_good,
        int local_claim_bad
    ){
        int n = complete_claim_good.size();
        if (i>=n){
            return 0;
        }
        if (is_bad[i] || 1<<i & local_claim_bad){
            return dfs_max_good_after(
                i+1,
                is_bad,
                complete_claim_good, 
                complete_claim_bad,
                local_claim_good, 
                local_claim_bad
            );
        }
        if (1<<i & local_claim_good){
            return 1 + dfs_max_good_after(
                i+1,
                is_bad,
                complete_claim_good, 
                complete_claim_bad,
                local_claim_good, 
                local_claim_bad
            );
        } else{
            // assume bad
            int assume_i_bad_local_claim_bad = local_claim_bad | 1<<i;
            int assume_i_bad = dfs_max_good_after(
                i+1,
                is_bad,
                complete_claim_good, 
                complete_claim_bad,
                local_claim_good, 
                assume_i_bad_local_claim_bad
            );

            // assume good
            int assume_i_good_local_claim_good = local_claim_good | complete_claim_good[i];
            int assume_i_good_local_claim_bad = local_claim_bad | complete_claim_bad[i];
            int assume_i_good = INT32_MIN;
            if ((assume_i_good_local_claim_good & assume_i_good_local_claim_bad) == 0){
                assume_i_good = 1 + dfs_max_good_after(
                    i+1,
                    is_bad,
                    complete_claim_good, 
                    complete_claim_bad,
                    assume_i_good_local_claim_good, 
                    assume_i_good_local_claim_bad
                );
            }
            
            return max(
                assume_i_bad,
                assume_i_good
            );
        }
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
