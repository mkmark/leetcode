#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>
#include <string>

int main()
{
    int n = 6;
    std::vector<std::vector<int>> input = {{3,0},{3,1},{3,2},{3,4},{5,4}};

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.findMinHeightTrees(n, input);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << " µs" << std::endl;

    for (auto i: output){
        std::cout << i << ' ';
    }

    return 0;
}