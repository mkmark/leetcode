#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>
#include <string>

int main()
{
    std::vector<std::vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.eventualSafeNodes(graph);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    for (auto i: output){
        std::cout << i << ' ';
    }

    return 0;
}