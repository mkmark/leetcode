/*
author: mark@mkmark.net
time: O()
space: O()

Runtime
1124 ms
Beats
64.94%
Memory
169.2 MB
Beats
18.18%
*/

#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const uint N = 501;

class Solution {
 private:
  int* parent;
  int* union_size;
  vector<unordered_set<int>> neighbours;

  inline int get_sid(int x) {
    auto parent_x = parent + x;
    if (x == *parent_x) return x;
    return *parent_x = get_sid(*parent_x);
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

  vi is_root_node_id;

  /// @brief int group.is_valid_group(){
  ///     return group.has_exactly_1_parent_node &&
  ///     group.remove_that_parent_node.get_all_subgroups.are_valid_groups
  /// }
  /// @param members
  /// @return If any group has 0 parent node: group not valid, globally return 0
  /// instantly. If any group has >1 parent nodes: nonstatic group, globally to
  /// return 2, but keep looking
  int check_group(vi& members) {
    int group_size = size(members);
    if (group_size == 1) {
      return 1;
    }
    int root_node_count = 0;
    vi root_node_ids;

    for (auto& member : members) {
      if (size(neighbours[member]) == group_size - 1) {
        root_node_ids.push_back(member);
        is_root_node_id[member] = 1;
        ++root_node_count;
      }
    }
    auto res = 1;
    if (root_node_count == 0) {
      return 0;
    } else if (root_node_count > 1) {
      res = 2;
    }
    for (auto& member : members) {
      if (is_root_node_id[member]) {
        continue;
      } else {
        for (auto& root_node_id : root_node_ids) {
          neighbours[member].erase(root_node_id);
        }
      }
      /// reset relavent union set
      parent[member] = member;
      union_size[member] = 1;
    }

    /// reunion set
    for (auto& member : members) {
      if (is_root_node_id[member]) {
        continue;
      } else {
        for (auto& neighbour : neighbours[member]) {
          if (member < neighbour) {
            union_set(member, neighbour);
          }
        }
      }
    }

    unordered_map<int, vi> groups;
    /// enforce sid, get groups
    for (auto& member : members) {
      if (is_root_node_id[member]) {
        continue;
      } else {
        auto sid = get_sid(member);
        parent[member] = sid;
        groups[sid].push_back(member);
      }
    }

    for (auto& kgroup : groups) {
      auto check_res = check_group(kgroup.second);
      if (check_res == 0) {
        return 0;
      } else if (check_res == 2) {
        res = 2;
      }
    }

    return res;
  }

 public:
  int checkWays(vector<vector<int>>& pairs) {
    /// compress the index
    int compress[N];
    fill(compress, compress + N, -1);
    int n = 0;
    for (auto& pair : pairs) {
      if (compress[pair[0]] != -1) {
        pair[0] = compress[pair[0]];
      } else {
        compress[pair[0]] = n;
        pair[0] = n++;
      }
      if (compress[pair[1]] != -1) {
        pair[1] = compress[pair[1]];
      } else {
        compress[pair[1]] = n;
        pair[1] = n++;
      }
    }

    /// union set
    int _parent[n];
    int _union_size[n];
    parent = _parent;
    union_size = _union_size;
    iota(parent, parent + n, 0);
    fill(union_size, union_size + n, 1);

    neighbours.resize(n);
    for (auto& pair : pairs) {
      union_set(pair[0], pair[1]);
      neighbours[pair[0]].emplace(pair[1]);
      neighbours[pair[1]].emplace(pair[0]);
    }

    int gid = get_sid(0);
    for (int i = 1; i < n; ++i) {
      if (get_sid(i) != gid) {
        return 0;
      }
    }

    is_root_node_id.resize(n);

    vi group(n);
    iota(all(group), 0);
    return check_group(group);
  }
};

const static auto initialize = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
