#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>

std::vector<int> arr = {8,4,5,1,9,8,6,5,6,9,7,3,8,3,6,7,10,11,6,4};
int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.recoverArray(arr);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    for (int i: output){
        std::cout << i << ' ';
    }

    return 0;
}