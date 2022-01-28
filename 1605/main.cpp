#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>
#include <tgmath.h>     // pow

int main()
{
    std::vector<int> rowSum = {5,7,10,0,1};
    std::vector<int> colSum = {8,6,9};

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.restoreMatrix(rowSum, colSum);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    for (auto i: output){
        for (int j: i){
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}