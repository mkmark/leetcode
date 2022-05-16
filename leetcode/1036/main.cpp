/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>
#include "../../lib/LeetCodeInput.hpp"
#include "solution.cpp"
using namespace std;

int main()
{
    LeetCodeInput li("29.in");

    vector<vector<int>> mat_1 = li.get_vvi(0);
    // vector<vector<int>> mat_1 = {};
    vector<int> arr_1 = li.get_vi(1);
    vector<int> arr_2 = li.get_vi(2);
    // int num_1 = li.get_i(0);
    // string s_1 = li.get_s(0);

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Solution solution;
    auto output = solution.isEscapePossible(mat_1, arr_1, arr_2);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time difference = " << chrono::duration_cast<chrono::microseconds> (end - begin).count() << "µs" << endl;

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
