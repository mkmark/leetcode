#include <vector>
#include <iostream>
#include "solution-2.cpp"
#include <chrono>

int main()
{
    // std::vector<std::vector<int>> mat = {{}};
    std::vector<int> arr = {23,14,17,5,19,2,0,18,15,12,2,8,21,3,3,1,6,5,11,17,3,7,14,13};
    // int num = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.maximumInvitations(arr);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    std::cout << output;

    // for (int i: output){
    //     std::cout << i << ' ';
    // }

    // for (auto i: output){
    //     for (int j: i){
    //         std::cout << j << ' ';
    //     }
    //     std::cout << '\n';
    // }

    return 0;
}