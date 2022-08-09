/*
author: mark@mkmark.net
time: O()
space: O()

Runtime: 1029 ms, faster than 34.12% of C++ online submissions for Number of Ways to Separate Numbers.
Memory Usage: 185.8 MB, less than 9.52% of C++ online submissions for Number of Ways to Separate Numbers.

dfs + dp + sum dp + suffix array
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

/**
 * @brief suffix array using SA-IS 
 * 
 */
class SuffixArray {
public:
    using size_type = unsigned;
    using pointer = size_type*;
    using const_pointer = const size_type*;

private:
    std::unique_ptr<size_type[]> data;

public:
    /// suffix array
    pointer sa;
    /// rank
    pointer rk;
    /// longest common prefix
    pointer ht;
    /// max longest common prefix
    // size_type max_lcp = 0;
    /// max longest common prefix position
    // size_type max_lcp_pos = 0;

private:
    template <typename S>
    static bool substring_equal(const S& s, size_type p1, size_type p2, size_type len)
    {
        for (size_type i = 0; i < len; ++i)
            if (s[p1 + i] != s[p2 + i])
                return false;
        return true;
    }

    template <typename S>
    static void induced_sort(
        const S& s,
        pointer sa,
        bool* type,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m,
        size_type n0)
    {
        std::fill_n(sa, n, 0);
        lbuk[0] = 0;
        for (size_type i = 1; i < m; ++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n0; i-- > 0;)
            sa[--sbuk[s[pos[i]]]] = pos[i];
        sbuk[m - 1] = n;
        for (size_type i = 1; i < m; ++i)
            sbuk[i - 1] = lbuk[i];
        sa[lbuk[s[n - 1]]++] = n - 1;
        for (size_type i = 0; i < n; ++i)
            if (sa[i] > 0 && !type[sa[i] - 1])
                sa[lbuk[s[sa[i] - 1]]++] = sa[i] - 1;
        lbuk[0] = 0;
        for (size_type i = 1; i < m; ++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n; i-- > 0;)
            if (sa[i] > 0 && type[sa[i] - 1])
                sa[--sbuk[s[sa[i] - 1]]] = sa[i] - 1;
    }

    /**
     * @brief time: O(n), space: O(n)
     * https://doi.org/10.1109%2FDCC.2009.42,
     * https://zork.net/~st/jottings/sais.html
     * @tparam S 
     * @param s 
     * @param sa 
     * @param type 
     * @param len 
     * @param pos 
     * @param lbuk 
     * @param sbuk 
     * @param n 
     * @param m bucket sort bucket size
     */
    template <typename S>
    static void sais(
        const S& s,
        pointer sa,
        bool* type,
        pointer len,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m)
    {
        type[n - 1] = false;
        for (size_type i = n - 1; i-- > 0;)
            type[i] = s[i] != s[i + 1] ? s[i] < s[i + 1] : type[i + 1];
        size_type n0 = 0;
        for (size_type i = 1; i < n; ++i)
            if (!type[i - 1] && type[i])
                pos[n0++] = i;
        std::fill_n(len, n, 0);
        for (size_type p = n - 1, i = n0; i-- > 0; p = pos[i])
            len[pos[i]] = p - pos[i] + 1;
        std::fill_n(sbuk, m, 0);
        for (size_type i = 0; i < n; ++i)
            ++sbuk[s[i]];
        for (size_type i = 1; i < m; ++i)
            sbuk[i] += sbuk[i - 1];
        induced_sort(s, sa, type, pos, lbuk, sbuk, n, m, n0);
        sbuk[m - 1] = n;
        for (size_type i = 1; i < m; ++i)
            sbuk[i - 1] = lbuk[i];
        size_type m0 = -1;
        size_type ppos = -1, plen = 0;
        for (size_type i = 0; i < n; ++i) {
            if (len[sa[i]] == 0)
                continue;
            if (len[sa[i]] != plen || !substring_equal(s, sa[i], ppos, plen))
                ++m0;
            plen = len[sa[i]];
            len[sa[i]] = m0;
            ppos = sa[i];
        }
        pointer s0 = sa;
        pointer sa0 = sa + n0;
        for (size_type i = 0; i < n0; ++i)
            s0[i] = len[pos[i]];
        if (++m0 < n0)
            sais(s0, sa0, type + n, len, pos + n0, lbuk, lbuk + n0, n0, m0);
        else
            for (size_type i = 0; i < n0; ++i)
                sa0[s0[i]] = i;
        for (size_type i = 0; i < n0; ++i)
            pos[i + n0] = pos[sa0[i]];
        induced_sort(s, sa, type, pos + n0, lbuk, sbuk, n, m, n0);
    }

public:
    /**
     * @brief Construct a new Suffix Array object
     * 
     * @param s sequence
     * @param n sequence length
     * @param m bucket size
     */
    template <class S>
    SuffixArray(S& s, size_type n, size_type m)
        : data(std::make_unique<size_type[]>(3 * n))
        , sa(data.get())
        , rk(sa + n)
        , ht(rk + n)
        // , max_lcp_pos(n)
    {
        const auto type = std::make_unique<bool[]>(2 * n);
        const auto lbuk = std::make_unique<size_type[]>(std::max(n, m));
        const auto sbuk = std::make_unique<size_type[]>(m);
        sais(s, sa, type.get(), rk, ht, lbuk.get(), sbuk.get(), n, m);
        /// kaisa algorithm
        /// seems to be reusing rk and ht for different purpose than sais
        for (size_type i = 0; i < n; ++i)
            /// rk is actually sa's index, i.e. sa[rk[i]] = i
            rk[sa[i]] = i;
        for (size_type k = 0, i = 0; i < n; ++i) {
            if (rk[i] == 0)
                continue;
            if (k > 0)
                --k;
            for (size_type j = sa[rk[i] - 1], l = n - std::max(i, j); k < l; ++k)
                if (s[i + k] != s[j + k])
                    break;

            // if (k > max_lcp){
            //     max_lcp = k;
            //     max_lcp_pos = sa[rk[i]];
            // }

            /// actually, lcp[i] = ht[sa[i]], i.e. lcp[sa[rk[i]]] = k;
            ht[rk[i]] = k;
        }
    }

    // size_type suffix(size_type p) const
    // {
    //     return sa[p];
    // }

    // size_type rank(size_type p) const
    // {
    //     return rk[p];
    // }

    // size_type height(size_type p) const
    // {
    //     return ht[p];
    // }
};

class Solution {
public:
    int n;
    /// dp[i][j] = sum(dp[j+1][2j-i .. n]), if flag
    ///            sum(dp[j+1][2j-i+1 .. n]), otherwise

    /// sumdp[i][j] = sum(dp[i][j .. n]), j>i
    /// dp[i][j] = sumdp[j+1][n] - sumdp[j+1][2j-i], if flag
    ///            sumdp[j+1][n] - sumdp[j+1][2j-i+1], otherwise
    vvi * ptr_dp;
    vvi * ptr_dpsum;
    vi * ptr_dpsum_caled;
    string * ptr_num;
    unsigned * rk;
    vector<vector<unsigned>> * ptr_lcp;

    int numberOfCombinations(string& num) {
        if (num[0] == 0) return 0;
        ptr_num = & num;
        n = size(num);
        
        vvi dp(n, vi(n, -1));
        ptr_dp = & dp;
        vvi dpsum(n, vi(n+1));
        ptr_dpsum = & dpsum;
        vi dpsum_caled(n, n);
        ptr_dpsum_caled = & dpsum_caled;
        SuffixArray suffixArray(num, n, 128);
        rk = suffixArray.rk;
        vector<vector<unsigned>> lcp(n, vector<unsigned>(n, UINT32_MAX));
        ptr_lcp = & lcp;
        for (int i = 0; i < n; ++i){
            for (int j = i+1; j < n; ++j){
                lcp[i][j] = min(lcp[i][j-1], suffixArray.ht[j]);
            }
        }

        int res=0;
        for (int i=0; i<n; ++i){
            res += dfs_comb(0, i);
            res %= 1000000007;
        }
        return res;
    }

    inline int get_min_nxt_end(int& l, int& r){
        int nxt_l = r+1;
        if ((n-1-nxt_l)<(r-l)) return 0;
        if (rk[nxt_l] < rk[l] && ((*ptr_lcp)[rk[nxt_l]][rk[l]] <= r-l)){
            return r*2+2-l;
        } else {
            return r*2+1-l;
        }
    }

    /**
     * @brief 
     * 
     * @param l current begin
     * @param r current rbegin
     * @param num 
     * @param dp 
     * @return int 
     */
    int dfs_comb(int l, int r){
        if ((*ptr_dp)[l][r] > -1) return (*ptr_dp)[l][r];
        if ((*ptr_num)[l]=='0') return (*ptr_dp)[l][r]=0;
        if (r == n-1) return (*ptr_dp)[l][r] = 1;

        int min_nxt_end = get_min_nxt_end(l, r);

        if (min_nxt_end){
            if (min_nxt_end < (*ptr_dpsum_caled)[r+1]){
                for (int i=(*ptr_dpsum_caled)[r+1]-1; i>=min_nxt_end; --i){
                    (*ptr_dpsum)[r+1][i] = (*ptr_dpsum)[r+1][i+1] + dfs_comb(r+1, i);
                    (*ptr_dpsum)[r+1][i] %= 1000000007;
                }
                (*ptr_dpsum_caled)[r+1] = min_nxt_end;
            }
            (*ptr_dp)[l][r] = (*ptr_dpsum)[r+1][min_nxt_end];
            (*ptr_dp)[l][r] %= 1000000007;
            return (*ptr_dp)[l][r];
        } else {
            return (*ptr_dp)[l][r] = 0;
        }
    }
};

const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
