#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>

int main()
{
    std::vector<std::vector<int>> mat = {{3,2},{4,3},{4,4},{2,5}};
    std::vector<int> arr = {};
    int num = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.mostPoints(mat);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    std::cout << output << std::endl;

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