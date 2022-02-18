#include <bits/stdc++.h>
#include "../../notes/leetcode.hpp"
#include "solution.cpp"
using namespace std;

int main()
{
    // vector<string> lines = get_lines("x.in");
    // vector<vector<int>> mat_1 = s2vvi(lines[0]);
    // vector<int> arr_1 = s2vi(lines[0]);
    // int num_1 = s2i(lines[0]);
    // string s_1 = lines[0];

    vector<vector<int>> mat_1 = {{}};
    vector<int> arr_1 = {};
    int num_1 = 0;
    string s_1 = "";

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Solution solution;
    auto output = solution.solution();
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
