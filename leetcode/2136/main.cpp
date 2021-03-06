#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>

int main()
{
    std::vector<std::vector<int>> mat = {{}};
    std::vector<int> arr1 = {1,2,3,2};
    std::vector<int> arr2 = {2,1,2,1};
    int num = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.earliestFullBloom(arr1, arr2);
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