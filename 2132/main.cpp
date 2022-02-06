#include <vector>
#include <iostream>
#include "solution-2.cpp"
#include <chrono>

int main()
{
    std::vector<std::vector<int>> mat = {{1,1,1,0},{0,0,0,1},{1,1,1,0},{1,1,0,0},{0,0,0,0},{0,1,0,1},{0,1,0,1},{1,1,1,0},{1,0,1,1},{0,0,0,1}};
    std::vector<int> arr = {};
    int h = 13;
    int w = 6;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.possibleToStamp(mat, h, w);
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