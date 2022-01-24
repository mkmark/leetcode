#include <vector>
#include <iostream>
#include "solution.cpp"
#include <chrono>
#include <tgmath.h>     // pow

int main()
{
    std::vector<int> original = {0,-2,-3,4,-6,4};
    // std::vector<int> original = {2,2,-4,-4,5};
    // std::vector<int> original = {1,2,-3};
    int n = original.size();
    std::vector<int> sums;
    for (int i = 0; i<pow(2,n); ++i){
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            int i_bins_j = (i >> j) & 1;
            sum += i_bins_j * original[j];
        }
        sums.push_back(sum);
    }

    for (int i: sums){
        std::cout << i << ' ';
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution solution;
    auto output = solution.recoverArray(n, sums);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << "[µs]" << std::endl;

    for (int i: output){
        std::cout << i << ' ';
    }

    return 0;
}