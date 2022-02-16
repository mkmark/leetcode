#include <vector>
#include <iostream>
#include "solution_3.cpp"
#include <chrono>

int main()
{
    std::vector<std::vector<int>> mat = {{}};
    std::vector<int> arr = {1,2,3,4,5,6};
    int num = 3;
    string s = "";

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.maximumANDSum(arr, num);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "µs" << std::endl;

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
