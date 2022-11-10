/*
author: mark@mkmark.net
time: O(n2)
space: O(n)

Runtime
229 ms
Beats
71.21%
Memory
41.8 MB
Beats
93.94%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
 private:
  int* parent;
  int* union_size;

  int get_set(int x) {
    if (x == parent[x]) return x;
    return parent[x] = get_set(parent[x]);
  }

  void union_set(int a, int b) {
    a = get_set(a);
    b = get_set(b);
    if (a != b) {
      if (union_size[a] < union_size[b]) {
        swap(a, b);
      }
      parent[b] = a;
      union_size[a] += union_size[b];
    }
  }

 public:
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    uint n = size(graph);
    uint m = size(initial);

    int _parent[n];
    int _union_size[n];
    parent = _parent;
    union_size = _union_size;

    iota(parent, parent + n, 0);
    fill(union_size, union_size + n, 1);

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (graph[i][j]) {
          union_set(i, j);
        }
      }
    }

    /// get_set all
    for (int i = 0; i < n; ++i) {
      parent[i] = get_set(i);
    }

    /// remember final union set
    int parent_all[n];
    int union_size_all[n];
    copy(parent, parent + n, parent_all);
    copy(union_size, union_size + n, union_size_all);

    /// per iter memory to record to_reunion node by removing a node
    int to_reunion[n];
    uint to_reunion_size = 0;

    /// per iter memory to record seen sid
    int seen_sid[n];
    memset(seen_sid, 0, sizeof(int) * n);

    int min_infected_count = INT_MAX;
    int res = INT_MAX;

    for (int i = 0; i < m; ++i) {
      /// del initial[i]
      int to_reunion_sid = get_set(initial[i]);
      /// get and reset all to_reunion nodes
      for (int j = 0; j < n; ++j) {
        if (get_set(j) == to_reunion_sid && j != initial[i]) {
          parent[j] = j;
          union_size[j] = 1;
          to_reunion[to_reunion_size++] = j;
        }
      }

      /// reunion nodes
      for (int x = 0; x < to_reunion_size; ++x) {
        int p = to_reunion[x];
        for (int q = 0; q < n; ++q) {
          if (q != initial[i]) {
            if (graph[p][q]) {
              union_set(p, q);
            }
          }
        }
      }

      int infected_count = 0;
      /// calculate total infected
      for (int j = 0; j < m; ++j) {
        if (j == i) {
          continue;
        }
        int sid = get_set(initial[j]);
        if (seen_sid[sid]) {
          continue;
        } else {
          infected_count += union_size[sid];
          seen_sid[sid] = 1;
        }
      }

      /// record result
      if (infected_count < min_infected_count) {
        min_infected_count = infected_count;
        res = initial[i];
      } else if (infected_count == min_infected_count) {
        res = min(res, initial[i]);
      }

      /// clear to_reunion
      to_reunion_size = 0;
      /// reset union set
      copy(parent_all, parent_all + n, parent);
      copy(union_size_all, union_size_all + n, union_size);
      /// clear seen_sid
      memset(seen_sid, 0, sizeof(int) * n);
    }

    return res;
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
