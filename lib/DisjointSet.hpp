/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class DisjointSet {
 public:
  /// array
  static const int MAX_SIZE = 10000;
  T parent[MAX_SIZE];
  T union_size[MAX_SIZE];
  ///

  /// vector
  // vector<T> parent;
  // vector<T> union_size;
  ///

  DisjointSet(int max_size) {
    /// array
    iota(parent, parent + max_size, 0);
    fill(union_size, union_size + max_size, 1);
    ///

    /// vector
    // parent.resize(max_size);
    // union_size.resize(max_size);
    // iota(begin(parent), end(parent), 0);
    // fill(begin(union_size), end(union_size), 1);
    ///
  }

  inline int get_sid(int x) {
    if (x == parent[x]) return x;
    return parent[x] = get_sid(parent[x]);
  }

  inline void union_set(int a, int b) {
    a = get_sid(a);
    b = get_sid(b);
    if (a != b) {
      if (union_size[a] < union_size[b]) {
        swap(a, b);
      }
      parent[b] = a;
      union_size[a] += union_size[b];
    }
  }
};
