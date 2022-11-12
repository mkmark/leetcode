/*
author: mark@mkmark.net
time: O(n)
space: O(n)

Runtime
0 ms
Beats
100%
Memory
6.4 MB
Beats
69.7%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

constexpr int MOD = 1e9 + 7;
constexpr int NMAX = 2e4 + 1;

int a[NMAX];
int e[NMAX];
int i[NMAX];
int o[NMAX];
int u[NMAX];
int calced = 1;

class Solution {
 private:
  inline void add_mod(int& a, int& b) {
    a += b;
    a %= MOD;
  };

  inline int get_res(int n) {
    int res = 0;
    add_mod(res, a[n]);
    add_mod(res, e[n]);
    add_mod(res, i[n]);
    add_mod(res, o[n]);
    add_mod(res, u[n]);
    return res;
  }

 public:
  Solution() {
    a[1] = 1;
    e[1] = 1;
    i[1] = 1;
    o[1] = 1;
    u[1] = 1;
  }

  int countVowelPermutation(int n) {
    if (n > calced) {
      for (int x = calced + 1; x <= n; ++x) {
        int y = x - 1;

        // a[x] = e[y] + i[y] + u[y];
        // e[x] = a[y] + i[y];
        // i[x] = e[y] + o[y];
        // o[x] = i[y];
        // u[x] = i[y] + o[y];

        /// this can be omited but dangerous; without this, should calced be a
        /// class member, a new solution (for leetcode parallel) would use the
        /// same mem address as before, causing a[x] to have correct value
        /// before calc, causing the result to be doubled
        a[x] = 0;
        e[x] = 0;
        i[x] = 0;
        o[x] = 0;
        u[x] = 0;

        add_mod(a[x], e[y]);
        add_mod(a[x], i[y]);
        add_mod(a[x], u[y]);

        add_mod(e[x], a[y]);
        add_mod(e[x], i[y]);

        add_mod(i[x], e[y]);
        add_mod(i[x], o[y]);

        add_mod(o[x], i[y]);

        add_mod(u[x], i[y]);
        add_mod(u[x], o[y]);
      }
      calced = n;
    }
    return get_res(n);
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
