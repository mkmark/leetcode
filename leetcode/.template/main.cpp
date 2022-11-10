/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>

#include "../../lib/LeetCodeInputTemplate.hpp"
#include "solution.cpp"
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {
  LeetCodeInput li("0.in");

  int i = 0;
  auto l0 = li.get<vvi>(i++);

  chrono::steady_clock::time_point begin = chrono::steady_clock::now();
  Solution solution;
  auto output = solution.solution(l0);
  chrono::steady_clock::time_point end = chrono::steady_clock::now();
  cout << "Time difference = "
       << chrono::duration_cast<chrono::microseconds>(end - begin).count()
       << "µs" << endl;

  cout << output << endl;

  // for (int i: output){
  //     cout << i << ' ';
  // }

  // for (auto i: output){
  //     for (int j: i){
  //         cout << j << ' ';
  //     }
  //     cout << '\n';
  // }

  return 0;
}
