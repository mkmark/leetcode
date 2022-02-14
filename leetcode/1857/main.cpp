#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>
#include <string>

int main()
{
    std::string colors = "aaa";
    std::vector<std::vector<int>> edges = {{1,2}, {2,1}};

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.largestPathValue(colors, edges);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    std::cout << output;

    return 0;
}