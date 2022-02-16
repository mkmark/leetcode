#include <bits/stdc++.h>
#include "solution.cpp"
using namespace std;

int main()
{
    vector<vector<int>> mat = {{}};
    vector<int> arr = {4,2,0,3,2,5};
    int num = 0;
    string s = "";

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Solution solution;
    auto output = solution.trap(arr);
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
