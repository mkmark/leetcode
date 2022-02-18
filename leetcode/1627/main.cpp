#include <bits/stdc++.h>
#include "../../lib/leetcode_input.hpp"
#include "solution.cpp"
using namespace std;

int main()
{
    leetcode_input li("57.in");

    vector<vector<int>> mat_1 = li.get_vvi(2);
    int num_1 = li.get_i(0);
    int num_2 = li.get_i(1);

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Solution solution;
    auto output = solution.areConnected(num_1, num_2, mat_1);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time difference = " << chrono::duration_cast<chrono::microseconds> (end - begin).count() << "µs" << endl;

    // cout << output << endl;

    for (int i: output){
        cout << i << ' ';
    }

    // for (auto i: output){
    //     for (int j: i){
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}
