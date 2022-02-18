#include <bits/stdc++.h>
#include "solution.cpp"
using namespace std;

int main()
{
    vector<vector<int>> mat = {{}};
    vector<int> arr = {5,4,2,6,3,1,0,7};
    int num = 0;
    string s = "";

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    Solution solution;
    auto output = solution.minSwapsCouples(arr);
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
