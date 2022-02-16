#include <bits/stdc++.h>
#include "solution_1.cpp"
using namespace std;

int main()
{
    vector<vector<int>> mat = {{}};
    vector<int> arr = {};
    int num = 0;
    string s = "0";

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Solution solution;
    auto output = solution.minimumTime(s);
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
