#include <vector>
#include <iostream>
#include "solution.h"
#include <chrono>

std::vector<int> arr = {2,1,3,1,2,3,3};
int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.getDistances(arr);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    for (int i: output){
        std::cout << i << ' ';
    }
}