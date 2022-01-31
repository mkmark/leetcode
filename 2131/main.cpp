#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>
#include <string>

int main()
{
    // std::vector<std::vector<int>> mat = {{}};
    std::vector<string> arr = {"em","pe","mp","ee","pp","me","ep","em","em","me"};
    // int num = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.longestPalindrome(arr);
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