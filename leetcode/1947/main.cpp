#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>

int main()
{
    std::vector<std::vector<int>> mat1 = {{0,1,0,1,1,1},{1,0,0,1,0,1},{1,0,1,1,0,0}};
    std::vector<std::vector<int>> mat2 = {{1,0,0,0,0,1},{0,1,0,0,1,1},{0,1,0,0,1,1}};
    std::vector<int> arr = {};
    int num = 0;
    string s = "";

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.maxCompatibilitySum(mat1, mat2);
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
